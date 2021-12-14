#include "info_dict.hpp"

#ifndef SINGLE_INFO_DICT_H
#define SINGLE_INFO_DICT_H

class SingleFileInfoDict : InfoDict
{
  public:
    long long length;
    string md5sum;
    SingleFileInfoDict(string raw_info_dict);
};

#endif
