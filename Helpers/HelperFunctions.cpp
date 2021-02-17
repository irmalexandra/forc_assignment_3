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

void build_tree(std::set<std::pair<char, int>, comp> frequency_table) {
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










