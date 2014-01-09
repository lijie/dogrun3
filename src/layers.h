#pragma once
#include "cocos2d.h"
#include "sprites.h"
#include "menu_items.h"

USING_NS_CC;

class DogLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(DogLayer);

  void MenuClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCSprite *bg_;
  DogSprite *dog_;
};

class DogMenuLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(DogMenuLayer);

  void MenuClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCMenu *menu_;
};

class MainMenuLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(MainMenuLayer);

  void MenuClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCMenu *menu_;
};

class UserLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(UserLayer);
  void MenuClickCallback(CCObject* sender);
protected:
  CCSprite *plank_;
  CCMenu *mail_menu_;
};

