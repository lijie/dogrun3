#ifndef  __DOGRUN2_UI_CINFIG_INIT__
#define  __DOGRUN2_UI_CINFIG_INIT__
#include "common.h"
#include "protocol/uiconfig.pb.h"

dogrun2::UIItemConfArray* GetUITrainCfg();
dogrun2::UIItemConfArray* GetUIPlayCfg();
int UIConfigInit();
#endif
