#include "single_info_dict.hpp"
#include "multi_info_dict.hpp"
#include "info_dict.hpp"
#include "bencode.hpp"
#include <vector>
using std::vector;

info_dict_type InfoDict::GetDictType(string torrent_data)
{
  if (torrent_data.find("d5:filesl") != string::npos)
  {
    return info_dict_type::MULTI_FILE;
  }
  return info_dict_type::SINGLE_FILE;
}

InfoDict::InfoDict(string raw_info_dict)
{
  auto info_data = bencode::boost_decode_view(raw_info_dict);
  auto dict_value = boost::get<bencode::dict_view>(info_data);
  piece_length = std::get<long long>(dict_value.find("piece length")->second);
  pieces = std::get<string>(dict_value.find("pieces")->second).c_str();
  auto priv_result = dict_value.find("private");
  if (priv_result != dict_value.end())
  {
    private_sign = std::get<long long>(priv_result->second);
  }
  name = std::get<string>(dict_value.find("name")->second);
}

MultiFileInfoDict::MultiFileInfoDict(string raw_info_dict)
: InfoDict(raw_info_dict)
{
  auto info_data = bencode::boost_decode_view(raw_info_dict);
  auto dict_value = boost::get<bencode::dict_view>(info_data);
  auto raw_files = std::get<vector<bencode::data>>(dict_value.find("files")->second);

  for (auto & element : raw_files)
  {
    files.push_back(SingleFileInfo(element));
  }
}

SingleFileInfo::SingleFileInfo(bencode::data raw_single_info)
{
  
}