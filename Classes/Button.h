//
//  Button.h
//  Button
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#ifndef __Button__Button__
#define __Button__Button__

#include "cocos2d.h"

using namespace cocos2d;

class Button : public CCNode, public CCTouchDelegate
{
private:
    CCLabelTTF* label;
    CCSprite* image;
    CCObject* target;
    SEL_MenuHandler selector;
    
    bool init();
    void resetTextureSize();
    
public:
    CREATE_FUNC(Button);
    
    virtual void setContentSize(const CCSize& contentSize);
    virtual void onEnter();
    virtual void onExit();
    
    const char* getText();
    void setText(const char* text);
    void setText(const char* text, const char* fontName, float fontSize);
    
    void setImageFile(const char* filename);
    void setImageTexture(CCTexture2D* texture);
    
    void setTarget(CCObject* target, SEL_MenuHandler selector);
    
    bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
};

#endif /* defined(__Button__Button__) */
