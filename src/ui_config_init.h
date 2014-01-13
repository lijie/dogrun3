#ifndef  __DOGRUN2_UI_CINFIG_INIT__
#define  __DOGRUN2_UI_CINFIG_INIT__
#include "protocol/uiconfig.pb.h"

class dogrun2::UIItemConfArray;
dogrun2::UIItemConfArray* GetUITrainCfg();
dogrun2::UIItemConfArray* GetUIPlayCfg();
int UIConfigInit();

#endif
