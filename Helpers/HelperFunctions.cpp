#include "HelperFunctions.h"

using namespace std;

bool comparer(Node* first, Node* second){
    return first->get_data()->get_frequency() > second->get_data()->get_frequency();
}

map<char, int>* make_frequency_table(vector<char> *file_content) {
    auto* frequency_map = new map<char, int>;

    for (const auto letter:*file_content){
        if (letter != '\n'){
            (*frequency_map)[letter] += 1;
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
        right =  roots.back();
        roots.pop_back();
        left = roots.back();
        roots.pop_back();
        Node *new_node = new Node(left, right);
        roots.push_back(new_node);

    }
    return roots.back();
}

void make_compression_keys(Node* current_node, char *key, map<char, char*> *key_map, int *depth){

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
}

map<char, char*>* make_compression_keys(Node *root){
    auto *key_map = new map<char, char*>;
    char *key = new char[256]{'\0'};
    auto* depth = new int(0);

    make_compression_keys(root, key, key_map, depth);

    for(auto const& [key, value]: *key_map){
        cout << "Key: " << key << " Value: " << value << endl;
    }



    delete depth;
    return key_map;

}






int VectorToInt(vector<char> v)
{
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    cout << endl;
    reverse(v.begin(), v.end());
    int decimal = 1;
    int total = 0;
    for (auto& it : v)
    {
        total += ((int)it - '0' )* decimal;
        decimal *= 10;
    }
    return total;
}





