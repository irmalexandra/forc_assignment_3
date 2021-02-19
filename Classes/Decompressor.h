#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include "../Helpers/HelperFunctions.h"

#ifndef FORC_PA_3_HUFFMANENCODER_H
#define FORC_PA_3_ENCODER_H

using namespace std;

class Decompressor {

public:
    Decompressor();
    void build_tree_from_keys(deque<char> value, char key, Node* current_node);
    Node build_key_tree(const map<char, deque<char>>& keys);

private:
    Node* key_map_root;
};


#endif //FORC_PA_3_HUFFMANENCODER_H
