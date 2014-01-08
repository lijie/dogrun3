#include "game_scene.h"
#include "dog.h"
#include "layers.h"
#include "sprites.h"
#ifdef LINUX
#include "unistd.h"
#endif

static void AddSearchPath() {
#ifdef LINUX
  char fullpath[256] = {0};
  ssize_t length = readlink("/proc/self/exe", fullpath, sizeof(fullpath)-1);

  if (length <= 0) {
        return;
  }

  fullpath[length] = '\0';
  std::string appPath = fullpath;
  string path = appPath.substr(0, appPath.find_last_of("/"));
  path += "/../../Resources";
  CCFileUtils::sharedFileUtils()->addSearchPath(path.c_str());
#endif
#ifdef WIN32
  CCFileUtils::sharedFileUtils()->addSearchPath("Resources");
#endif
}

bool GameScene::init()
{
  //////////////////////////////
  // 1. super init first
  if (!CCScene::init())
    return false;

  // init plist
  CCSpriteFrameCache *c = CCSpriteFrameCache::sharedSpriteFrameCache();
  CCFileUtils::sharedFileUtils()->addSearchPath("Resources");
  AddSearchPath();

  const std::vector<std::string>& v = CCFileUtils::sharedFileUtils()->getSearchPaths();
  for (size_t i = 0; i < v.size(); i++) {
    printf("search path %s\n", v[i].c_str());
  }
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
