#include <string>
#include <vector>
using std::string;
using std::vector;

#ifndef TORRENT_FILE_H
#define TORRENT_FILE_H

class TorrentFile
{
  public:
    string announce_url;
    vector<vector<string>> announce_list;
    long long creation_date;
    string comment;
    string created_by;
    string encoding;
    TorrentFile(string raw_torrent_file);
};

#endif
