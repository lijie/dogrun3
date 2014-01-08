#pragma once
#include "cocos2d.h"
#include "sprites.h"
#include "menu_items.h"

USING_NS_CC;

class DogLayer : public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(DogLayer);

    void MenuClickCallback(CCObject* pSender);
protected:
    CCSprite *bg_;
    DogSprite *dog_;
    CCMenu *main_menu_;
};

class UserLayer : public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(UserLayer);
protected:
    CCSprite *bg_;
};

