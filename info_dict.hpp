#include <string>
using std::string;

#ifndef INFO_DICT_H
#define INFO_DICT_H

typedef enum
{
  MULTI_FILE,
  SINGLE_FILE
}info_dict_type;

class InfoDict {
  public:
    long long piece_length;
    char const *pieces;
    long long private_sign;
    string name;
    static info_dict_type GetDictType(string& raw_info_dict);
    InfoDict(string& raw_info_dict);
};

#endif
