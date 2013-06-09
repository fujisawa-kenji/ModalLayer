//
//  ModalLayer.cpp
//  ModalLayer
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#include "ModalLayer.h"

void ModalLayer::onEnter()
{
    CCLayerColor::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, INT_MIN, true);
}

void ModalLayer::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayerColor::onExit();
}

bool ModalLayer::containsPoint(cocos2d::CCNode *node, cocos2d::CCPoint point)
{
    CCNode* parent = node->getParent();
    if (parent == NULL)
        parent = node;
    
    point = parent->convertToNodeSpace(point);
    
    return node->boundingBox().containsPoint(point);
}

bool ModalLayer::canTouch(cocos2d::CCNode *node)
{
    CCTouchDelegate* delegate = dynamic_cast<CCTouchDelegate*>(node);
    return CCDirector::sharedDirector()->getTouchDispatcher()->findHandler(delegate) != NULL;
}

CCArray* ModalLayer::getSortedChildren(cocos2d::CCNode *node)
{
    CCArray* children = node->getChildren();
    if (children == NULL)
        return NULL;
    
    CCArray* sorted = CCArray::create();
    sorted->initWithArray(children);
    for (int i = 0; i < sorted->count(); i++)
    {
        for (int j = 1; j < sorted->count() - i; j++)
        {
            CCNode* a = (CCNode*)sorted->objectAtIndex(j - 1);
            CCNode* b = (CCNode*)sorted->objectAtIndex(j);
            if (a->getZOrder() < b->getZOrder())
                sorted->exchangeObjectAtIndex(j - 1, j);
        }
    }
    
    return sorted;
}

CCNode* ModalLayer::getChildAt(cocos2d::CCNode *node, cocos2d::CCPoint point)
{
    CCArray* children = this->getSortedChildren(node);
    if (children == NULL)
        return this->canTouch(node) ? node : NULL;
    
    for (int i = 0; i < children->count(); i++)
    {
        CCNode* child = (CCNode*)children->objectAtIndex(i);
        if (this->containsPoint(child, point))
        {
            CCNode* target = this->getChildAt(child, point);
            if (target != NULL)
                return target;
        }
    }
    
    return this->canTouch(node) ? node : NULL;
}

bool ModalLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint point = pTouch->getLocation();
    if (!this->containsPoint(this, point))
        return false;
    
    this->touchOrigin = this->getChildAt(this, point);
    if (this->touchOrigin == this)
        this->touchOrigin = NULL;
    
    CCTouchDelegate* delegate = dynamic_cast<CCTouchDelegate*>(this->touchOrigin);
    if (delegate != NULL)
        delegate->ccTouchBegan(pTouch, pEvent);
    
    return true;
}

void ModalLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCTouchDelegate* delegate = dynamic_cast<CCTouchDelegate*>(this->touchOrigin);
    if (delegate != NULL)
        delegate->ccTouchMoved(pTouch, pEvent);
}

void ModalLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCTouchDelegate* delegate = dynamic_cast<CCTouchDelegate*>(this->touchOrigin);
    if (delegate != NULL)
        delegate->ccTouchEnded(pTouch, pEvent);
}

void ModalLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCTouchDelegate* delegate = dynamic_cast<CCTouchDelegate*>(this->touchOrigin);
    if (delegate != NULL)
        delegate->ccTouchCancelled(pTouch, pEvent);
}
