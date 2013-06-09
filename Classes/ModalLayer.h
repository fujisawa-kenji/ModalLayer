//
//  ModalLayer.h
//  ModalLayer
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#ifndef __ModalLayer__ModalLayer__
#define __ModalLayer__ModalLayer__

#include "cocos2d.h"

using namespace cocos2d;

class ModalLayer : public CCLayerColor
{
private:
    CCNode* touchOrigin;
    
    bool containsPoint(CCNode* node, CCPoint point);
    bool canTouch(CCNode* node);
    CCNode* getChildAt(CCNode* node, CCPoint point);
    CCArray* getSortedChildren(CCNode* node);
    
public:
    CREATE_FUNC(ModalLayer);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent);
};

#endif /* defined(__ModalLayer__ModalLayer__) */
