//
//  Tower.h
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#ifndef __MyTDGame__Tower__
#define __MyTDGame__Tower__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Enemy;
class GameScene;

class Tower: public CCNode {
private:
    int range;
    int damage;
    float rate;
    GameScene* gameScene;
    
    void Shoot(float t);
    void DmageEnemy();
    void RemoveBullet(CCSprite* bullet);
    
public:
    Tower(char* pImgName, CCPoint pos, int rge, int d, float rte, GameScene* game);
    ~Tower();
    void draw();
    void update(float t);
    
    
    CC_SYNTHESIZE(CCSprite*, mySprite, MySprite);
    CC_SYNTHESIZE(Enemy*, target, Target);
    CC_SYNTHESIZE(CCPoint, currentPoint, CurrentPoint);
};

#endif /* defined(__MyTDGame__Tower__) */
