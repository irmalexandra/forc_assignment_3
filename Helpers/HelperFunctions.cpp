#include "HelperFunctions.h"
#include <algorithm>

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
void make_compression_keys(Node *current_node, int key, map<char, int> *key_map){

    make_compression_keys(current_node->get_left(), key, key_map);
    make_compression_keys(current_node->get_right(), key, key_map);
}

void make_compression_keys(Node *root){
    map<char, int> *key_map;
    int key = 0;

    make_compression_keys(root.get_left(), key, key_map);

}












