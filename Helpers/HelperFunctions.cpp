#include "HelperFunctions.h"
#include <algorithm>
#include <bitset>
using namespace std;

bool comparer(Node* first, Node* second){
    return first->get_data()->get_frequency() > second->get_data()->get_frequency();
}

map<char, int> make_frequency_table(vector<char> *file_content) {
    map<char, int> frequency_map;

    for (const auto letter:*file_content){
        if (letter != '\n'){
            frequency_map[letter] += 1;
        }
    }

    delete file_content;
    return frequency_map;
}

Node* build_tree(map<char, int> frequency_table) {
    Node *left;
    Node *right;
    std::vector <Node*> roots;

    for (auto pair:frequency_table){
        roots.push_back(new Node( new Data( pair.second, pair.first)));
    }

    while (roots.size() != 1){
        sort(roots.begin(), roots.end(), comparer);
        left =  roots.back();
        roots.pop_back();
        right = roots.back();
        roots.pop_back();
        Node *new_node = new Node(left, right);
        roots.push_back(new_node);

    }
    return roots.back();
}


void make_compression_keys(Node* current_node, bitset<256> *key, map<char, bitset<256>> *key_map, unsigned int *depth){

    if (current_node->get_data()->get_value() != '\0'){
        key_map->insert(std::pair<char, bitset<256>>(current_node->get_data()->get_value(), key));

    }
/*    key[depth] = 0;
    depth++;
    make_compression_keys(current_node->get_left(), key, key_map, depth);
    key[depth] = 1;
    make_compression_keys(current_node->get_right(), key, key_map, depth);
    depth--;*/
}



void make_compression_keys(Node *root){
    auto *key_map = new map<char, bitset<256>>;
    bitset<256> key(0);
    key = 1;
    key<<=1;



    cout << key << endl;
    key_map->insert(std::pair<char, bitset<256>>(root->get_data()->get_value(), key));

    auto* depth = new unsigned int(0);
//    make_compression_keys(root, key, key_map, depth);

    delete depth;
    return;

}












