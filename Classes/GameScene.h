//
//  GameScene.h
//  MyTDGame
//
//  Created by PYgzx on 14-9-6.
//
//

#ifndef __MyTDGame__GameScene__
#define __MyTDGame__GameScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class GameScene:public CCLayer {
private:
    CCArray * bases;
    CCArray * enemise;
    int wave;
    int difficulty;
    int hp;
    int money;
    CCLabelTTF *label;

    void LoadBases();
    bool LoadWave();
    bool CanBuyTower();
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(GameScene);
    
    CCArray* GetEnemies() const;
    void NoneEnemy();
    void BeAttacked();
};

#endif /* defined(__MyTDGame__GameScene__) */
