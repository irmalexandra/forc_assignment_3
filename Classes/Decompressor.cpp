//
// Created by emmik on 19/02/2021.
//

#include "Decompressor.h"



void Decompressor::build_tree_from_keys(deque<char> value, char key, Node* current_node){
    auto new_node = new Node;
    if(value.empty()){
        auto data = new Data(key);
        current_node->get_data()->set_value(key);
        return;
    }
    if(value[0] == '1'){
        current_node->set_right(new_node);
    }
    else if(value[0] == '0'){
        current_node->set_left(new_node);
    }
    value.pop_front();
    build_tree_from_keys(value, key, new_node);

};



Node Decompressor::build_key_tree(const map<char, deque<char>>& keys) {


    for(auto key : keys){
        cout << key.first << endl;
       build_tree_from_keys(key.second, key.first, this->key_map_root);
    };

    return Node(nullptr, nullptr);
}

Decompressor::Decompressor() {
    this->key_map_root = new Node();
}











