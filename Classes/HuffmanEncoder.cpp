#include "HuffmanEncoder.h"


HuffmanEncoder::HuffmanEncoder(vector<char> *file_content) {
    this->file_content = file_content;
    this->compression_keys = nullptr;
    this->frequency_table = nullptr;
    this->root = nullptr;
}

HuffmanEncoder::~HuffmanEncoder() {
    delete this->frequency_table;
    delete this->compression_keys;
    delete this->file_content;
}

void HuffmanEncoder::make_frequency_table() {
    auto* frequency_map = new map<char, int>;

    for (auto const letter:*this->file_content){
        if (letter != '\n'){
            (*frequency_map)[letter] += 1;
        }
    }
    this->frequency_table = frequency_map;
}

void HuffmanEncoder::build_tree() {
    Node *left;
    Node *right;
    std::vector <Node*> roots;

    for (auto pair:*this->frequency_table){
        roots.push_back(new Node( new Data( pair.second, pair.first)));
    }

    while (roots.size() != 1){
        sort(roots.begin(), roots.end(), comparer);
        right =  roots.back();
        roots.pop_back();
        left = roots.back();
        roots.pop_back();
        Node *new_node = new Node(left, right);
        roots.push_back(new_node);
    }
    this->root = roots.back();
}

void HuffmanEncoder::make_compression_keys(Node* current_node, char *key, map<char, char*> *key_map, int *depth){
    if (current_node->get_data()->get_value() != '\0'){
        char* temp_key = new char[256];
        copy(key, key+256, temp_key);
        key_map->insert(std::pair<char, char*>(current_node->get_data()->get_value(), temp_key));
        return;
    }
    key[*depth] = '0';
    (*depth)++;
    make_compression_keys(current_node->get_left(), key, key_map, depth);
    key[*depth] = 0;
    (*depth)--;
    key[*depth] = '1';
    (*depth)++;
    make_compression_keys(current_node->get_right(), key, key_map, depth);
    key[*depth] = 0;
    (*depth)--;
};

void HuffmanEncoder::make_compression_keys() {
    auto *key_map = new map<char, char*>;
    char *key = new char[256]{'\0'};
    auto* depth = new int(0);

    make_compression_keys(root, key, key_map, depth);

    for (auto const& key: *key_map){
        cout << "Key: " << key.first << " Value: " << key.second << endl;
    }
    this->compression_keys = key_map;
    delete depth;
}

map<char, char*>* HuffmanEncoder::get_compression_keys(){
    return this->compression_keys;
}

map<char, int>* HuffmanEncoder::get_frequency_table(){
    return this->frequency_table;
}

CompressionInfo HuffmanEncoder::get_compression_info(){
   return CompressionInfo(this->frequency_table, this->compression_keys);
}