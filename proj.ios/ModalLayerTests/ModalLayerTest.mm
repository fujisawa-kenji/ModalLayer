//
//  ModalLayerTest.m
//  ModalLayer
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#import "ModalLayerTest.h"
#import "ModalLayer.h"

@implementation ModalLayerTest

- (void)testTouch
{
    ModalLayer* layer = ModalLayer::create();
    layer->setContentSize(CCSize(300, 300));
    
    TouchableNode n1;
    n1.setContentSize(CCSize(50, 50));
    n1.setPosition(ccp(0, 0));
    layer->addChild(&n1);
    
    TouchableNode n2;
    n2.setContentSize(CCSize(50, 50));
    n2.setPosition(ccp(100, 100));
    layer->addChild(&n2);
    
    TouchableNode n3;
    n3.setContentSize(CCSize(10, 10));
    n3.setPosition(ccp(0, 0));
    n2.addChild(&n3);
    
    TouchableNode n4;
    n4.setContentSize(CCSize(10, 10));
    n4.setPosition(ccp(0, 0));
    layer->addChild(&n4, 10);
    
    STAssertFalse(n1.touchBegan, @"n1.touchBegan expected false, but was true");
    STAssertFalse(n2.touchBegan, @"n2.touchBegan expected false, but was true");
    STAssertFalse(n3.touchBegan, @"n3.touchBegan expected false, but was true");
    STAssertFalse(n4.touchBegan, @"n4.touchBegan expected false, but was true");
    STAssertFalse(n1.touchMoved, @"n1.touchMoved expected false, but was true");
    STAssertFalse(n2.touchMoved, @"n2.touchMoved expected false, but was true");
    STAssertFalse(n3.touchMoved, @"n3.touchMoved expected false, but was true");
    STAssertFalse(n4.touchMoved, @"n4.touchMoved expected false, but was true");
    STAssertFalse(n1.touchEnded, @"n1.touchEnded expected false, but was true");
    STAssertFalse(n2.touchEnded, @"n2.touchEnded expected false, but was true");
    STAssertFalse(n3.touchEnded, @"n3.touchEnded expected false, but was true");
    STAssertFalse(n4.touchEnded, @"n4.touchEnded expected false, but was true");
    STAssertFalse(n1.touchCancelled, @"n1.touchCancelled expected false, but was true");
    STAssertFalse(n2.touchCancelled, @"n2.touchCancelled expected false, but was true");
    STAssertFalse(n3.touchCancelled, @"n3.touchCancelled expected false, but was true");
    STAssertFalse(n4.touchCancelled, @"n4.touchCancelled expected false, but was true");
    
    CCPoint p1 = CCDirector::sharedDirector()->convertToGL(ccp(5, 5));
    CCTouch t1;
    t1.setTouchInfo(0, p1.x, p1.y);
    layer->ccTouchBegan(&t1, NULL);
    STAssertFalse(n1.touchBegan, @"n1.touchBegan expected false, but was true");
    STAssertFalse(n2.touchBegan, @"n2.touchBegan expected false, but was true");
    STAssertFalse(n3.touchBegan, @"n3.touchBegan expected false, but was true");
    STAssertTrue(n4.touchBegan, @"n4.touchBegan expected true, but was false");
    
    layer->ccTouchMoved(NULL, NULL);
    STAssertFalse(n1.touchMoved, @"n1.touchMoved expected false, but was true");
    STAssertFalse(n2.touchMoved, @"n2.touchMoved expected false, but was true");
    STAssertFalse(n3.touchMoved, @"n3.touchMoved expected false, but was true");
    STAssertTrue(n4.touchMoved, @"n4.touchMoved expected true, but was false");
    
    layer->ccTouchEnded(NULL, NULL);
    STAssertFalse(n1.touchEnded, @"n1.touchEnded expected false, but was true");
    STAssertFalse(n2.touchEnded, @"n2.touchEnded expected false, but was true");
    STAssertFalse(n3.touchEnded, @"n3.touchEnded expected false, but was true");
    STAssertTrue(n4.touchEnded, @"n4.touchEnded expected true, but was false");
    
    layer->ccTouchCancelled(NULL, NULL);
    STAssertFalse(n1.touchCancelled, @"n1.touchCancelled expected false, but was true");
    STAssertFalse(n2.touchCancelled, @"n2.touchCancelled expected false, but was true");
    STAssertFalse(n3.touchCancelled, @"n3.touchCancelled expected false, but was true");
    STAssertTrue(n4.touchCancelled, @"n4.touchCancelled expected true, but was fales");
    
    n4.touchBegan = false;
    n4.touchMoved = false;
    n4.touchEnded = false;
    n4.touchCancelled = false;
    
    CCPoint p2 = CCDirector::sharedDirector()->convertToGL(ccp(105, 105));
    CCTouch t2;
    t2.setTouchInfo(1, p2.x, p2.y);
    layer->ccTouchBegan(&t2, NULL);
    STAssertFalse(n1.touchBegan, @"n1.touchBegan expected false, but was true");
    STAssertFalse(n2.touchBegan, @"n2.touchBegan expected false, but was true");
    STAssertTrue(n3.touchBegan, @"n3.touchBegan expected true, but was false");
    STAssertFalse(n4.touchBegan, @"n4.touchBegan expected false, but was true");
    
    layer->ccTouchMoved(NULL, NULL);
    STAssertFalse(n1.touchMoved, @"n1.touchMoved expected false, but was true");
    STAssertFalse(n2.touchMoved, @"n2.touchMoved expected false, but was true");
    STAssertTrue(n3.touchMoved, @"n3.touchMoved expected true, but was false");
    STAssertFalse(n4.touchMoved, @"n4.touchMoved expected false, but was true");
    
    layer->ccTouchEnded(NULL, NULL);
    STAssertFalse(n1.touchEnded, @"n1.touchEnded expected false, but was true");
    STAssertFalse(n2.touchEnded, @"n2.touchEnded expected false, but was true");
    STAssertTrue(n3.touchEnded, @"n3.touchEnded expected true, but was false");
    STAssertFalse(n4.touchEnded, @"n4.touchEnded expected false, but was true");
    
    layer->ccTouchCancelled(NULL, NULL);
    STAssertFalse(n1.touchCancelled, @"n1.touchCancelled expected false, but was true");
    STAssertFalse(n2.touchCancelled, @"n2.touchCancelled expected false, but was true");
    STAssertTrue(n3.touchCancelled, @"n3.touchCancelled expected true, but was false");
    STAssertFalse(n4.touchCancelled, @"n4.touchCancelled expected false, but was true");
}

@end

TouchableNode::TouchableNode()
: touchBegan(false)
, touchMoved(false)
, touchEnded(false)
, touchCancelled(false)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool TouchableNode::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    this->touchBegan = true;
    return true;
}

void TouchableNode::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    this->touchMoved = true;
}

void TouchableNode::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    this->touchEnded = true;
}

void TouchableNode::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    this->touchCancelled = true;
}
