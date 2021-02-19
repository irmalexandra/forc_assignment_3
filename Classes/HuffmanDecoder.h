
#ifndef FORC_PA_3_HUFFMANDECODER_H
#define FORC_PA_3_HUFFMANDECODER_H

#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include "../Helpers/HelperFunctions.h"

using namespace std;

class HuffmanDecoder {
public:
    void populate_from_file(string file_name);
    vector<string> get_compressed_strings();
    map<char, deque<char>> get_key_map();
private:
    map<char, deque<char>> key_map;
    vector<string> compressed_strings;
};


#endif //FORC_PA_3_HUFFMANDECODER_H
