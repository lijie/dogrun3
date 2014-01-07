#pragma once
#include "cocos2d.h"
#include "dog.h"

USING_NS_CC;

class DogSprite : public CCSprite, public CCTargetedTouchDelegate
{
public:
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();
	bool containsTouchLocation(CCTouch* touch);

	CREATE_FUNC(DogSprite);
protected:
	CCPoint last_xy_;
	CCRect rect();
	Dog* dog_;
};

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

class GameScene :
	public CCScene
{
public:
	static const int kLayerDog = 1;
	static const int kLayerUser = 4;
	static const int kLayerMenu = 3;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    // static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);

protected:
	CCLayer *doglayer_;
	UserLayer *ul_;
};

