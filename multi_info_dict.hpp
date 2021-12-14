#include <vector>
#include <map>
#include <bencode.hpp>
using std::vector;
using std::map;
#include "info_dict.hpp"
#include "single_file_info.hpp"

#ifndef MULTI_INFO_DICT_H
#define MULTI_INFO_DICT_H

class MultiFileInfoDict : InfoDict
{
  public:
    vector<SingleFileInfo> files;
    MultiFileInfoDict(string raw_info_dict);
};

#endif
