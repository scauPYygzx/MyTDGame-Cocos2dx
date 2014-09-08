//
//  OverScene.h
//  MyTDGame
//
//  Created by PYgzx on 14-9-8.
//
//

#ifndef __MyTDGame__OverScene__
#define __MyTDGame__OverScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class OverScene: public CCLayer {
private:
    bool status;
    CCLabelTTF *label;
public:
    bool init();
    static CCScene* scene();
    void SetStatus(bool);
    void ReFresh();
    CREATE_FUNC(OverScene);
    
};

#endif /* defined(__MyTDGame__OverScene__) */
