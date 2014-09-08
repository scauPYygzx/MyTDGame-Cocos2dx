//
//  Enemy.h
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#ifndef __MyTDGame__Enemy__
#define __MyTDGame__Enemy__

#include <iostream>
#include "cocos2d.h"
#include "GameMap.h"

USING_NS_CC;
class GameScene;

class Enemy: public CCNode {
private:
    int maxHp;
    int hp;
    int speed;
    GameMap gameMap;
    CCPoint nextPoint;
    GameScene* gameScene;
    bool isActive;
    
    void draw();
    void update(float t);
    void Remove();
    
public:
    Enemy(char* pEnenmyName, int maxhp, int spd, GameScene* game);
    Enemy(CCString* pEnenmyName, int maxhp, int spd, GameScene* game);
    ~Enemy();
    void BeAttacked(int damge);
    void DoActive(float t);
    
    CC_SYNTHESIZE(bool, isAlive, IsAlive);
    CC_SYNTHESIZE(CCSprite*, mySprite, MySprite);
    CC_SYNTHESIZE(CCPoint, currentPoint, CurrentPosition);
};

#endif /* defined(__MyTDGame__Enemy__) */
