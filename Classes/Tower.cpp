//
//  Tower.cpp
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#include "Tower.h"
#include "GameScene.h"
#include "Enemy.h"
#include "global.h"

Tower::Tower(char* pImgName, CCPoint pos, int rge, int d, float rte, GameScene* game) {
#ifdef COCOS2D_DEBUG
    CCLog("New Tower(%d %d %.2f) at (%d %d)",rge,d,rte,(int)pos.x, (int)pos.y);
#endif
    
    mySprite = CCSprite::create(pImgName);
    mySprite->setPosition(pos);
    currentPoint = pos;
    this->cocos2d::CCNode::addChild(mySprite);
    
    range = rge;
    damage = d;
    rate = rte;
    target = NULL;
    gameScene = game;

    
    this->scheduleUpdate();
    this->schedule(schedule_selector(Tower::Shoot), rate, -1, 0);
}

Tower::~Tower() {
    
}

void Tower::draw() {
    ccDrawColor4F(0, 0, 0, 200);
    ccDrawCircle(mySprite->getPosition(), range, 360, 30, false, 1, 1);
    
    CCNode::draw();
}

void Tower::update(float t) {
#ifdef COCOS2D_DEBUG
    
#endif
    if(target) {
        if(!IsCrash(currentPoint, range, target->getCurrentPosition(), 20)) {
            target = NULL;
        }
    }
    else {
        CCObject *pObject;
        CCARRAY_FOREACH(gameScene->GetEnemies(), pObject) {
            Enemy* enemy = (Enemy*)pObject;
            if(IsCrash(enemy->getCurrentPosition(), 20, currentPoint,range)) {
                target = enemy;
                break;
            }
        }
    }
    
}

void Tower::Shoot(float t) {
    if(target && target->getIsAlive()) {
        CCSprite *bullet = CCSprite::create("bullet.png");
        bullet->setPosition(currentPoint);
        gameScene->addChild(bullet);
        CCMoveTo *to = CCMoveTo::create(0.14, target->getCurrentPosition());
        CCCallFunc * func = CCCallFunc::create(this, callfunc_selector(Tower::DmageEnemy));
        CCCallFuncN *funcN = CCCallFuncN::create(this, callfuncN_selector(Tower::RemoveBullet));
        CCSequence * seq = CCSequence::create(to,func,funcN,NULL);
        bullet->runAction(seq);
    }
}

void Tower::DmageEnemy() {
    if(target) {
        target->BeAttacked(damage);
        if(!target->getIsAlive())
            target = NULL;
    }
}

void Tower::RemoveBullet(CCSprite* bullet) {
    bullet->getParent()->removeChild(bullet);
}