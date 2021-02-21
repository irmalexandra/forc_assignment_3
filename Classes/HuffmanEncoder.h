#ifndef FORC_PA_3_HUFFMANENCODER_H
#define FORC_PA_3_HUFFMANENCODER_H

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include "../Classes/Node.h"
#include "../Classes/Data.h"
#include "../Helpers/HelperFunctions.h"

struct EncodeInfo{
  EncodeInfo() = default;

  CompressionInfo(map<char, int>* frequency_table, map<char, char*>* key_map, vector<char>* file_content){
      this->frequency_table = frequency_table;
      this->key_map = key_map;
      this->file_content = file_content;
      this->count_bits();
  }

//  ~EncodeInfo(){ TODO:fix?
//      delete this->file_content;
//      delete this->compression_keys;
//      delete[] this->frequency_table;
//  }

  void count_bits(){
      for (auto freq:*this->frequency_table){
          this->bit_count += freq.second * strlen(this->key_map->find(freq.first)->second);
      }
  }

  map<char, int>* frequency_table = nullptr;
  map<char, char*>* key_map = nullptr;
  vector<char>* file_content = nullptr;
  unsigned int bit_count = 0;
};

class HuffmanEncoder {
public:
    HuffmanEncoder() = default;
    explicit HuffmanEncoder(vector<char>* file_content);

    ~HuffmanEncoder();

    void encode(vector<char> *file_content);
    EncodeInfo get_compression_info();

private:
    Node* root;
    vector<char>* file_content;
    map<char, int>* frequency_table;
    map<char, char*>* compression_keys;
};


#endif //FORC_PA_3_HUFFMANENCODER_H
