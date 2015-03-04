#include "HelloWorldScene.h"
#include "SoundManager.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);


	//ÒôÐ§

	SoundManager::getInstance()->playMusic("tower_bgm.mp3");

	
	schedule(schedule_selector(HelloWorld::playSound),0.2f);
    
    return true;
}

void HelloWorld::playSound(float dt)
{
	//unschedule(schedule_selector(HelloWorld::playSound));
    float rand = CCRANDOM_0_1() * 10;
    if(rand < 3)
    {
	SoundManager::getInstance()->playSound("popup_sliding.mp3");
    }
    else if(rand < 6)
    {
       SoundManager::getInstance()->playSound("stage_matching.mp3");
        
    }
    else if(rand < 9 )
    {
        SoundManager::getInstance()->playSound("popup_sliding.mp3");
        SoundManager::getInstance()->playSound("stage_matching.mp3");
    }
    else
    {
        SoundManager::getInstance()->playSound("popup_sliding.mp3");
        SoundManager::getInstance()->playSound("stage_matching.mp3");
        SoundManager::getInstance()->playSound("level_up.mp3");
        SoundManager::getInstance()->playSound("stage_matching.mp3");
    }
        
	//scheduleOnce(schedule_selector(HelloWorld::playSound),CCRANDOM_0_1());

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
