#include "game_scene.h"
#include "dog.h"
#include "layers.h"
#include "sprites.h"
#include "event_mgr.h"

bool GameScene::init() {
  //////////////////////////////
  // 1. super init first
  if (!CCScene::init())
    return false;

  // init plist
  CCSpriteFrameCache *c = CCSpriteFrameCache::sharedSpriteFrameCache();
  CCFileUtils::sharedFileUtils()->addSearchPath("Resources");
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

  user_layer_ = UserLayer::create();
  this->addChild(user_layer_, kLayerUser);

  MainMenuLayer* main_menu_layer = MainMenuLayer::create();
  DogMenuLayer* dog_menu_layer = DogMenuLayer::create();
  menu_layer_ = CCLayerMultiplex::create(main_menu_layer, dog_menu_layer, NULL);

  this->addChild(menu_layer_, kLayerMenu);

  menu_flag_ = 0;
  menu_layer_->switchTo(menu_flag_);


  EventMgr::Instance().Register(1, this, callfuncO_selector(GameScene::MenuClickCallback));

  return true;
}

void GameScene::MenuClickCallback(CCObject* sender)
{
  menu_flag_ = (++menu_flag_)%2;
  menu_layer_->switchTo(menu_flag_);
}

void GameScene::menuCloseCallback(CCObject* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
  CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
  CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
#endif
}