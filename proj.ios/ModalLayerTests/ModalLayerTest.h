//
//  ModalLayerTest.h
//  ModalLayer
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#import <SenTestingKit/SenTestingKit.h>
#import "cocos2d.h"

using namespace cocos2d;

@interface ModalLayerTest : SenTestCase

@end

class TouchableNode : public CCNode, public CCTouchDelegate
{
public:
    TouchableNode();
    
    bool touchBegan;
    bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    
    bool touchMoved;
    void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
    
    bool touchEnded;
    void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
    
    bool touchCancelled;
    void ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent);
};
