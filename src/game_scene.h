#pragma once
#include "cocos2d.h"
#include "dog.h"

USING_NS_CC;
class DogLayer;
class UserLayer;

class GameScene :
  public CCScene
{
public:
  static const int kLayerDog = 1;
  static const int kLayerMenu = 3;
  static const int kLayerUser = 4;
  

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();  

  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  // static cocos2d::CCScene* scene();

  // a selector callback
  void menuCloseCallback(CCObject* pSender);

  // implement the "static node()" method manually

  void MenuClickCallback(CCObject* sender);
  CREATE_FUNC(GameScene);

protected:
  DogLayer *doglayer_;
  UserLayer *user_layer_;
  CCLayerMultiplex *menu_layer_;
  int menu_flag_;
};

