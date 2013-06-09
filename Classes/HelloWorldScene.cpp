#include "HelloWorldScene.h"
#include "Button.h"
#include "ModalLayer.h"
#include "CCScrollView.h"

using namespace cocos2d::extension;

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
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    
//    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - pLabel->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
//
//    // add "HelloWorld" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);
    
    ModalLayer* layer = ModalLayer::create();
    layer->initWithColor(ccc4(128, 128, 128, 128));
    layer->setContentSize(CCSize(visibleSize.width * 0.8f, visibleSize.height * 0.8f));
    layer->setPosition(ccp(visibleSize.width * 0.5f - layer->getContentSize().width * 0.5f, visibleSize.height * 0.5f - layer->getContentSize().height * 0.5f));
    this->addChild(layer, 10);
    
    Button* b1 = Button::create();
    b1->setText("behind layer");
    b1->setPosition(ccp(visibleSize.width * 0.5f - layer->getContentSize().width * 0.5f + 50, visibleSize.height * 0.5f - layer->getContentSize().height * 0.5f + 50));
    b1->setContentSize(CCSize(50, 50));
    b1->setTarget(this, menu_selector(HelloWorld::onTapped));
    this->addChild(b1, 0);
    
    Button* b2 = Button::create();
    b2->setText("on layer");
    b2->setPosition(ccp(50, 150));
    b2->setContentSize(CCSize(50, 50));
    b2->setTarget(this, menu_selector(HelloWorld::onTapped));
    layer->addChild(b2, 0);
    
    Button* b3 = Button::create();
    b3->setText("sprite");
    b3->setImageFile("HelloWorld.png");
    b3->setPosition(ccp(layer->getContentSize().width * 0.5f, layer->getContentSize().height * 0.5f));
    b3->setContentSize(CCSize(200, 200));
    b3->setTarget(this, menu_selector(HelloWorld::onTapped));
    layer->addChild(b3, 0);
    
    Button* b4 = Button::create();
    b4->setText("on sprite");
    b4->setPosition(ccp(50, 50));
    b4->setContentSize(CCSize(50, 50));
    b4->setTarget(this, menu_selector(HelloWorld::onTapped));
    b3->addChild(b4, 10);
    
    Button* b5 = Button::create();
    b5->setText("outside layer");
    b5->setPosition(ccp(visibleSize.width - 25, visibleSize.height - 25));
    b5->setContentSize(CCSize(50, 50));
    b5->setTarget(this, menu_selector(HelloWorld::onTapped));
    this->addChild(b5, 0);
    
    CCMenuItemImage* item1 = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this, menu_selector(HelloWorld::menuCloseCallback));
    CCMenu* menu1 = CCMenu::create(item1, NULL);
    menu1->setContentSize(item1->getContentSize());
    menu1->setPosition(ccp(visibleSize.width * 0.5f + layer->getContentSize().width * 0.5f - 10, visibleSize.height * 0.5f - layer->getContentSize().height * 0.5f + 10));
    this->addChild(menu1, 0);
    
    CCMenuItemImage* item2 = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this, menu_selector(HelloWorld::menuCloseCallback));
    CCMenu* menu2 = CCMenu::create(item2, NULL);
    menu2->setContentSize(item2->getContentSize());
    menu2->setPosition(ccp(layer->getContentSize().width - 30, 30));
    layer->addChild(menu2, 10);
    
    CCSprite* sprite1 = CCSprite::create("HelloWorld.png");
    CCScrollView* scroll1 = CCScrollView::create(CCSize(100, 100));
    scroll1->addChild(sprite1, 0, 0);
    scroll1->setPosition(ccp(50, layer->getContentSize().height));
    this->addChild(scroll1, 0);
    
    CCSprite* sprite2 = CCSprite::create("HelloWorld.png");
    CCScrollView* scroll2 = CCScrollView::create(CCSize(50, 50));
    scroll2->addChild(sprite2, 0, 0);
    scroll2->setPosition(ccp(layer->getContentSize().width - 50, layer->getContentSize().height - 50));
    layer->addChild(scroll2, 10);
    
    return true;
}

void HelloWorld::onTapped(cocos2d::CCObject *sender)
{
    Button* b = (Button*)sender;
    CCLog(b->getText());
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
