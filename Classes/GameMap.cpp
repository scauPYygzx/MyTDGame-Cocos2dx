//
//  GameMap.cpp
//  MyTDGame
//
//  Created by PYgzx on 14-9-7.
//
//

#include "GameMap.h"

GameMap::GameMap() {
    index = 0;
    size = 0;
    currentPoint = ccp(-1, -1);
}

GameMap::~GameMap() {
}

void GameMap::Load() {
    
}

CCPoint GameMap::GetFirstPoint() {
    assert(size > 0);
    return map[0];
}

CCPoint GameMap::GetNextPoint() {
    assert(index < size);
    index++;
    if(index == size) {
        return ccp(-1, -1);
    }
    else {
        return map[index];
    }
}

int GameMap::GetSize() {
    return size;
}

void GameMap::Add(int x, int y) {
    map.push_back(ccp((int)x,(int)y));
    size ++;
}