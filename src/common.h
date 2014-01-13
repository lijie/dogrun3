#ifndef  __DOGRUN2_COMMON__
#define  __DOGRUN2_COMMON__

#include <google/protobuf/stubs/common.h>
#include <string>
using std::string;

int ParseFromFile(const string& filepath,
                         google::protobuf::Message *output);

#endif
