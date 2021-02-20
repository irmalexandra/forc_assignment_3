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

struct CompressionInfo{
  CompressionInfo() = default;

  CompressionInfo(map<char, int>* frequency_table, map<char, char*>* key_map){
      this->frequency_table = frequency_table;
      this->key_map = key_map;
  }

  CompressionInfo(map<char, int>* frequency_table, map<char, char*>* key_map, vector<char>* file_content){
      this->frequency_table = frequency_table;
      this->key_map = key_map;
      this->file_content = file_content;
      this->count_bits();
  }

  ~CompressionInfo(){
      delete this->frequency_table;
      delete this->key_map;
      delete this->file_content;
  }

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

    void make_frequency_table();
    void build_tree();
    void make_compression_keys(Node* current_node, char* key, map<char, char*>* key_map, int* depth);
    void make_compression_keys();

    map<char, char*>* get_compression_keys();
    map<char, int>* get_frequency_table();
    CompressionInfo get_compression_info();

private:
    Node* root;
    vector<char>* file_content;
    map<char, int>* frequency_table;
    map<char, char*>* compression_keys;
};


#endif //FORC_PA_3_HUFFMANENCODER_H
