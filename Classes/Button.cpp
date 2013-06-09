//
//  Button.cpp
//  Button
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#include "Button.h"

bool Button::init()
{
    if (!CCNode::init())
        return false;
    
    CCSize size = this->getContentSize();
    
    this->setAnchorPoint(ccp(0.5f, 0.5f));
    
    this->label = CCLabelTTF::create("", "Thonburi", 24);
    this->label->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    this->label->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
    this->label->setHorizontalAlignment(kCCTextAlignmentCenter);
    this->addChild(this->label, 10);
    
    this->image = CCSprite::create();
    this->image->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    this->addChild(this->image, 0);
    
    return true;
}

void Button::onEnter()
{
    CCNode::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void Button::onExit()
{
    CCNode::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

const char* Button::getText()
{
    return this->label->getString();
}

void Button::setText(const char *text)
{
    this->label->setString(text);
}

void Button::setText(const char *text, const char *fontName, float fontSize)
{
    this->label->setString(text);
    this->label->setFontName(fontName);
    this->label->setFontSize(fontSize);
}

void Button::setImageFile(const char *filename)
{
    this->setImageTexture(CCTextureCache::sharedTextureCache()->addImage(filename));
}

void Button::setImageTexture(cocos2d::CCTexture2D *texture)
{
    if (texture == NULL)
        return;
    
    this->image->setTexture(texture);
    this->resetTextureSize();
}

void Button::setContentSize(const cocos2d::CCSize &contentSize)
{
    CCNode::setContentSize(contentSize);
    this->resetTextureSize();
    
    this->label->setPosition(ccp(contentSize.width * 0.5f, contentSize.height * 0.5f));
    this->image->setPosition(ccp(contentSize.width * 0.5f, contentSize.height * 0.5f));
}

void Button::resetTextureSize()
{
    CCTexture2D* texture = this->image->getTexture();
    if (texture == NULL)
        return;
    
    CCSize buttonSize = this->getContentSize();
    CCSize textureSize = texture->getContentSize();
    float scaleX = buttonSize.width / textureSize.width;
    float scaleY = buttonSize.height / textureSize.height;
    
    this->image->setTextureRect(CCRect(0, 0, textureSize.width, textureSize.height));
    this->image->setScale(fmin(scaleX, scaleY));
}

void Button::setTarget(cocos2d::CCObject *target, SEL_MenuHandler selector)
{
    this->target = target;
    this->selector = selector;
}

bool Button::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (this->target == NULL || this->selector == NULL)
        return false;
    
    CCPoint point = this->getParent()->convertToNodeSpace(pTouch->getLocation());
    if (!this->boundingBox().containsPoint(point))
        return false;
    
    return true;
}

void Button::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint point = this->getParent()->convertToNodeSpace(pTouch->getLocation());
    if (!this->boundingBox().containsPoint(point))
        return;
    
    CCObject* target = this->target;
    SEL_MenuHandler selector = this->selector;
    (target->*selector)(this);
}
