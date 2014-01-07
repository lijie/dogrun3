#include "GameScene.h"
#include "dog.h"

bool DogSprite::init()
{
  if (!CCSprite::init())
    return false;

  this->initWithSpriteFrameName("dog.png");
  dog_ = User::current()->dogs(0);
  return true;
}

CCRect DogSprite::rect()
{
    CCSize s = this->getTexture()->getContentSize();
    return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}

bool DogSprite::containsTouchLocation(CCTouch* touch)
{
    return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

void DogSprite::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite::onEnter();
}

bool DogSprite::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if (!containsTouchLocation(touch))
        return false;
    last_xy_ = touch->getLocation();
    return true;
}

void DogSprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

}

void DogSprite::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    CCPoint loc = touch->getLocation();
    float x, y;
    x = loc.x - last_xy_.x;
    y = loc.y - last_xy_.y;

    CCPoint pos = this->getPosition();
    this->setPosition(ccp(pos.x + x, pos.y + y));
    last_xy_ = loc;
}

void DogSprite::touchDelegateRetain()
{
    this->retain();
}

void DogSprite::touchDelegateRelease()
{
    this->release();
}

void DogSprite::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
} 

bool DogLayer::init()
{
    if (!CCLayer::init())
        return false;

    bg_ = CCSprite::create("background.png");
    bg_->setPosition(ccp(400, 240));
    this->addChild(bg_);

    dog_ = DogSprite::create();
    dog_->setPosition(ccp(400, 240));
    this->addChild(dog_);
    return true;
}

bool UserLayer::init()
{
    if (!CCLayer::init())
        return false;

    bg_ = CCSprite::create("plank.png");
    bg_->setPosition(ccp(400, 480 - 61));
    this->addChild(bg_, 1);
    return true;
}
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!CCScene::init())
        return false;

    // init plist
    CCSpriteFrameCache *c = CCSpriteFrameCache::sharedSpriteFrameCache();
    c->addSpriteFramesWithFile("dogrun2.plist", "dogrun2.png");

#if 0
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
#endif
    doglayer_ = DogLayer::create();
    this->addChild(doglayer_, kLayerDog);

    ul_ = UserLayer::create();
    this->addChild(ul_, kLayerUser);
    return true;
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}