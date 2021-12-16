#include <vector>
using std::vector;
#include <string>
using std::string;
#include "info_dict.hpp"
#include "bencode.hpp"

#ifndef SINGLE_FILE_INFO_H
#define SINGLE_FILE_INFO_H

class SingleFileInfo
{
  public:
    long long length;
    string md5sum;
    vector<string> path;
    SingleFileInfo(bencode::boost_data_view& raw_single_info);
};

#endif
