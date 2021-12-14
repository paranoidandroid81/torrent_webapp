#include <vector>
using std::vector;
#include "info_dict.hpp"

#ifndef SINGLE_FILE_INFO_H
#define SINGLE_FILE_INFO_H

class SingleFileInfo
{
  public:
    long long length;
    string md5sum;
    vector<string> path;
    SingleFileInfo(string raw_single_info);
};

#endif
