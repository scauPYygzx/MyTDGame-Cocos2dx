#include "HelloWorldScene.h"
#include "GameScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLOG("visibleSize = (%d, %d)",(int)visibleSize.width,(int)visibleSize.height);
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCLOG("origin = (%d, %d)",(int)origin.x, (int)origin.y);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("size = (%d, %d)",(int)size.width,(int)size.height);
    
    CCMenuItemFont *menuItem = CCMenuItemFont::create("Start Game", this, menu_selector(HelloWorld::OnStartGame));
    CCMenu *menu = CCMenu::create(menuItem,NULL);
    menu->setPosition(ccp(size.width/2,size.height/2));
    this->addChild(menu);
    
    
    return true;
}

void HelloWorld::OnStartGame(CCObject* pSender){
    CCLog("Start Game");
    GameScene *scene = GameScene::create();
    CCDirector::sharedDirector()->replaceScene((CCScene*)scene);
}

