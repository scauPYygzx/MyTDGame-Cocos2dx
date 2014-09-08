//
//  GameMap.h
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#ifndef __MyTDGame__GameMap__
#define __MyTDGame__GameMap__

#include <iostream>
#include "cocos2d.h"
#include <vector>

USING_NS_CC;
using std::vector;

class GameMap {
private:
    CCPoint currentPoint;
    vector<CCPoint> map;
    int size;
    int index;
    
public:
    GameMap();
    ~GameMap();
    void Load();
    CCPoint GetFirstPoint();
    CCPoint GetNextPoint();
    void Add(int x, int y);
    int GetSize();
};

#endif /* defined(__MyTDGame__GameMap__) */
