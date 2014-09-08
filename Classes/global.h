//
//  global.cpp
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#ifndef _GLOBAL_
#define _GLOBAL_

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

static bool IsCrash(CCPoint p1, int r1, CCPoint p2, int r2) {
    int x = (int)(p1.x - p2.x);
    int y = (int)(p1.y - p2.y);
    int r = r1 + r2;
    if(x * x + y * y <= r * r) {
        //CCLog("%f %f", sqrt(x*x+y*y),sqrt(r*r));
        return true;
    }
    return false;
}

#endif