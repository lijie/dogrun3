#include "ui_config_init.h"
#include "common.h"
#include "protocol/uiconfig.pb.h"

static dogrun2::UIItemConfArray *UITrainCfg = NULL;
static dogrun2::UIItemConfArray *UIPlayCfg = NULL;

dogrun2::UIItemConfArray* GetUITrainCfg() {
  return UITrainCfg;
}
dogrun2::UIItemConfArray* GetUIPlayCfg() {
  return UIPlayCfg;
}


int UIConfigInit() {
  printf("%s\n", __FUNCTION__);
  if (!UITrainCfg) {
    UITrainCfg = new dogrun2::UIItemConfArray;
    assert(UITrainCfg != NULL);
    ParseFromFile("etc/uitrain.cfg", UITrainCfg);
    assert(UITrainCfg != NULL);
  }
  if (!UIPlayCfg) {
    UIPlayCfg = new dogrun2::UIItemConfArray;
    assert(UIPlayCfg != NULL);
    ParseFromFile("etc/uiplay.cfg", UIPlayCfg);
    assert(UIPlayCfg != NULL);
  }
  return 0;
}

