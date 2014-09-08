//
//  OverScene.cpp
//  MyTDGame
//
//  Created by PYgzx on 14-9-8.
//
//

#include "OverScene.h"

CCScene* OverScene::scene() {
    CCScene *scene = CCScene::create();
    OverScene *layer = OverScene::create();
    scene->addChild(layer);
    return scene;
}

bool OverScene::init() {
    if(!CCLayer::init()) {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    label = CCLabelTTF::create("", "arial", 60);
    label->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(label);
    return true;
}

void OverScene::SetStatus(bool sta) {
    status = sta;
}

void OverScene::ReFresh() {
    CCString *str;
    if(status) {
        str = CCString::create("WIN!");
    }
    else {
        str = CCString::create("LOSE!");
    }
    label->setString(str->getCString());
}