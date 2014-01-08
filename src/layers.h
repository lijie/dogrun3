#pragma once
#include "cocos2d.h"

USING_NS_CC;

class DogLayer : public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(DogLayer);

protected:
    CCSprite *bg_;
    DogSprite *dog_;
};

class UserLayer : public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(UserLayer);
protected:
    CCSprite *bg_;
};

