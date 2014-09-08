//
//  GameScene.cpp
//  MyTDGame
//
//  Created by PYgzx on 14-9-6.
//
//


#include "GameScene.h"
#include "Tower.h"
#include "Enemy.h"
#include "global.h"
#include "OverScene.h"

CCScene* GameScene::scene() {
    CCScene *scene = CCScene::create();
    GameScene *layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init() {
    if(!CCLayer::init()) {
        return false;
    }
    
    setTouchEnabled(true);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *bg = CCSprite::create("bg.png");
    bg->setPosition(ccp(size.width/2,size.height/2));
    this->addChild(bg);
    
    LoadBases();
    enemise = CCArray::createWithCapacity(10);
    enemise->retain();

    hp = 3;
    money = 100;
    CCString* str = CCString::createWithFormat("HP: %d\nMoney: %d", hp,money);
    label = CCLabelTTF::create(str->getCString(), "Microsoft Yahei", 30);
    label->setPosition(ccp(size.width-100,600));
    label->setColor(ccc3(0,0,0));
    this->addChild(label);
    
    wave = 0;
    LoadWave();
    
    return true;
}


void GameScene::LoadBases() {
    CCArray *towersPosition = CCArray::createWithContentsOfFile("bases.plist");
    bases = CCArray::createWithCapacity(10);
    bases->retain();
    
    CCObject * pObject;
    int x, y;
    CCARRAY_FOREACH(towersPosition, pObject) {
        CCDictionary *pos = (CCDictionary*) pObject;
        CCSprite *base = CCSprite::create("base.png");
        this->addChild(base);
        
        x = ((CCString*)pos->objectForKey("x"))->intValue();
        y = ((CCString*)pos->objectForKey("y"))->intValue();
        base->setPosition(ccp(x,y));
        
        bases->addObject(base);
    }
}

bool GameScene::LoadWave() {
    CCArray *all = CCArray::createWithContentsOfFile("difficulty01.plist");
    if(wave >= all->count())
        return false;
    
    CCArray *currentWare = (CCArray*)all->objectAtIndex(wave);
    CCObject *pObject;
    CCString *image,*hp,*speed,*time;
    CCARRAY_FOREACH(currentWare, pObject) {
        CCDictionary * dir = (CCDictionary*)pObject;
        image = (CCString*)dir->objectForKey("image");
        hp = (CCString*)dir->objectForKey("hp");
        speed = (CCString*)dir->objectForKey("speed");
        time = (CCString*)dir->objectForKey("time");
        Enemy *enemy = new Enemy(image,hp->intValue(),speed->intValue(),this);
        enemise->addObject(enemy);
        this->addChild(enemy);
        enemy->scheduleOnce(schedule_selector(Enemy::DoActive), time->floatValue());
        enemy->autorelease();
        
    }
    wave ++;
    
    return true;
}

bool GameScene::CanBuyTower() {
    return true;
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent) {
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint pos = touch->getLocation();
    CCObject *pObject;
    CCARRAY_FOREACH(bases, pObject) {
        CCSprite* base = (CCSprite*)pObject;
        if(CanBuyTower() && base->boundingBox().containsPoint(pos) && !base->getUserData()) {
#ifdef COCOS2D_DEBUG
            
#endif        
            int range = random()%100 + 50;
            Tower *tower = new Tower("tower.png", base->getPosition(),range,1,1.0,this);
            this->addChild(tower);
            base->setUserData(tower);
            break;
        }
    }
}

CCArray* GameScene::GetEnemies() const {
    return enemise;
}

void GameScene::NoneEnemy() {
    if(!LoadWave()) {
        CCLog("win.");
        OverScene *overScene = OverScene::create();
        overScene->SetStatus(true);
        CCDirector::sharedDirector()->replaceScene((CCScene*)overScene);
        overScene->ReFresh();
    }
    else {
        CCLog("New Enemies.");
    }
}

void GameScene::BeAttacked() {
    hp--;
    if(hp <= 0) {
        CCLog("lose.");
        OverScene *overScene = OverScene::create();
        overScene->SetStatus(false);
        CCDirector::sharedDirector()->replaceScene((CCScene*)overScene);
        overScene->ReFresh();
    }
    CCString *str = CCString::createWithFormat("HP: %d\nMoney: %d", hp,money);
    label->setString(str->getCString());
}
