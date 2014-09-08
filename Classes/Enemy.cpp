//
//  Enemy.cpp
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#include "Enemy.h"
#include "GameScene.h"
#include "global.h"

Enemy::Enemy(char* pEnemyName, int maxhp, int spd, GameScene* game) {
    maxHp = maxhp;
    hp = maxHp;
    speed = spd;
    isAlive = true;
    gameScene = game;
    isActive = false;
    
    gameMap.Add(-30, 510);
    gameMap.Add(770,510);
    gameMap.Add(770,270);
    gameMap.Add(130,270);
    gameMap.Add(130,0);
    
    mySprite = CCSprite::create(pEnemyName);
    this->addChild(mySprite);
    currentPoint = gameMap.GetFirstPoint();
    mySprite->setPosition(currentPoint);
    nextPoint = gameMap.GetNextPoint();
    
    this->scheduleUpdate();
}

Enemy::Enemy(CCString* pEnemyName, int maxhp, int spd, GameScene* game) {
    maxHp = maxhp;
    hp = maxHp;
    speed = spd;
    isAlive = true;
    gameScene = game;
    isActive = false;
    
    gameMap.Add(-30, 510);
    gameMap.Add(770,510);
    gameMap.Add(770,270);
    gameMap.Add(130,270);
    gameMap.Add(130,0);
    
    mySprite = CCSprite::create(pEnemyName->getCString());
    this->addChild(mySprite);
    currentPoint = gameMap.GetFirstPoint();
    mySprite->setPosition(currentPoint);
    nextPoint = gameMap.GetNextPoint();
    
    this->scheduleUpdate();
}

Enemy::~Enemy() {
    
}

void Enemy::draw() {
    CCNode::draw();
}

void Enemy::update(float t) {
#ifdef COCOS2D_DEBUG
#endif
    if(!isActive)
        return;
    
    if(IsCrash(nextPoint, 1, currentPoint, 1)) {
        nextPoint = gameMap.GetNextPoint();
        if(nextPoint.x == -1.0 && nextPoint.y == -1.0) {
            Remove();
            gameScene->BeAttacked();
            return;
        }
    }
    
    CCPoint normalize = ccpNormalize(ccp(nextPoint.x-currentPoint.x,nextPoint.y-currentPoint.y));
    currentPoint.x += normalize.x*speed;
    currentPoint.y += normalize.y*speed;
    mySprite->setPosition(currentPoint);
}

void Enemy::BeAttacked(int damge) {
    hp -= damge;
    if(hp <= 0) {
        Remove();
        isAlive = false;
    }
}

void Enemy::Remove() {
    this->getParent()->removeChild(this, true);
    gameScene->GetEnemies()->removeObject(this);
    if(gameScene->GetEnemies()->count() <= 0) {
        gameScene->NoneEnemy();
    }
}

void Enemy::DoActive(float t) {
    isActive = true;
}
