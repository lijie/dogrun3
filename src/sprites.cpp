#include "game_scene.h"
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
  start_xy_ = touch->getLocation();
  return true;
}

void DogSprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
  CCPoint cur_xy = touch->getLocation();
  if(start_xy_.fuzzyEquals(cur_xy, 2.0f)) {
    //on_click
  }
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

