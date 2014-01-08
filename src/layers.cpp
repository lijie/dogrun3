#include "layers.h"

void DogLayer::MenuClickCallback(CCObject* pSender)
{
  int a = 0;
  a++;
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

  CCSprite* mail_sprite = CCSprite::create();
  mail_sprite->initWithSpriteFrameName("mail.png");

  CCSprite* friend_sprite = CCSprite::create();
  friend_sprite->initWithSpriteFrameName("friend.png");

  CCSprite* step_sprite = CCSprite::create();
  step_sprite->initWithSpriteFrameName("step.png");

  CCSprite* warehouse_sprite = CCSprite::create();
  warehouse_sprite->initWithSpriteFrameName("warehouse.png");

  CCSprite* gold_sprite = CCSprite::create();
  gold_sprite->initWithSpriteFrameName("gold.png");

  CCSprite* shop_sprite = CCSprite::create();
  shop_sprite->initWithSpriteFrameName("shop.png");

  CCSprite* reward_sprite = CCSprite::create();
  reward_sprite->initWithSpriteFrameName("reward.png");
  
  CCPoint base_Position = getPosition();
  CCMenuItemSprite* mail_item = CCMenuItemSprite::create(
    mail_sprite, mail_sprite, mail_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* friend_item = CCMenuItemSprite::create(
    friend_sprite, friend_sprite, friend_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  friend_item->setPosition( ccp(base_Position.x + 5,  base_Position.y + 5));
  
  CCMenuItemSprite* step_item = CCMenuItemSprite::create(
    step_sprite, step_sprite, step_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  step_item->setPosition( ccp(base_Position.x + 50,  base_Position.y + 5));

  CCMenuItemSprite* warehouse_item = CCMenuItemSprite::create(
    warehouse_sprite, warehouse_sprite, warehouse_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  warehouse_item->setPosition( ccp(base_Position.x + 60,  base_Position.y + 5));

  CCMenuItemSprite* gold_item = CCMenuItemSprite::create(
    gold_sprite, gold_sprite, gold_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  gold_item->setPosition( ccp(base_Position.x + 70,  base_Position.y + 5));

  CCMenuItemSprite* shop_item = CCMenuItemSprite::create(
    shop_sprite, shop_sprite, shop_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  gold_item->setPosition( ccp(base_Position.x + 70,  base_Position.y + 5));

  CCMenuItemSprite* reward_item = CCMenuItemSprite::create(
    reward_sprite, reward_sprite, reward_sprite, this, menu_selector(DogLayer::MenuClickCallback));
   reward_item->setPosition( ccp(base_Position.x + 80,  base_Position.y + 5));

  main_menu_ = CCMenu::create( mail_item, friend_item, step_item, warehouse_item,
    gold_item, shop_item, NULL);
  main_menu_->alignItemsVertically();
  CCSize s = CCDirector::sharedDirector()->getWinSize();

  int i=0;
  CCNode* child;
  CCArray * pArray = main_menu_->getChildren();
  CCObject* pObject = NULL;
  CCARRAY_FOREACH(pArray, pObject)
  {
    if(pObject == NULL)
      break;

    child = (CCNode*)pObject;

    CCPoint dstPoint = child->getPosition();
    int offset = (int) (s.width/2 + 50);
    if( i % 2 == 0)
      offset = -offset;

    child->setPosition( ccp( dstPoint.x + offset, dstPoint.y) );
    child->runAction( 
      CCEaseElasticOut::create(CCMoveBy::create(2, ccp(dstPoint.x - offset,0)), 0.35f) 
      );
    i++;
  }

  addChild(main_menu_);

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
