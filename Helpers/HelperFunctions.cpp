#include "HelperFunctions.h"


using namespace std;

set<pair<char, int>, comp> sort(map<char, int>& map_to_sort)
{
    return set<pair<char, int>, comp> (map_to_sort.begin(), map_to_sort.end());
}

set<pair<char, int>, comp> make_frequency_table(vector<char> *file_content) {
    map<char, int> frequency_map;

    for (const auto letter:*file_content){
        if (letter != '\n'){
            frequency_map[letter] += 1;
        }
    }

    delete file_content;
    return sort(frequency_map);
}

void build_tree(std::set<std::pair<char, int>, comp> frequency_table) {
    Node *left;
    Node *right;
    Node *root;
    std::vector <Node *> char_nodes;
    std::vector <Node *> roots;
    auto freq_vect = vector<pair<char, int>>{frequency_table.begin(), frequency_table.end()};



    while(!freq_vect.empty()){
        auto pair1 = freq_vect.back();
        freq_vect.pop_back();
        char_nodes.push_back(new Node(new Data(pair1.second, pair1.first)));
    }

    while (char_nodes.size() != 1){
        left = char_nodes[0];
        right = char_nodes[1];


    }

//    auto pair1 = freq_vect.back();
//    freq_vect.pop_back();
//    auto pair2 = freq_vect.back();
//    freq_vect.pop_back();
//
//    left = new Node(new Data(pair1.second, pair1.first));
//    right = new Node(new Data(pair2.second, pair2.first));
//    if (left->get_data()->get_frequency() < right->get_data()->get_frequency()){ //Gives the least frequent character the highest binary value
//        root = new Node(left, right);
//    }
//    else{
//        root = new Node(right, left);
//    }
//    roots.push_back(root);
//    while (!freq_vect.empty()){*
//        auto pair1 = freq_vect.back();
//        freq_vect.pop_back();
//        auto pair2 = freq_vect.back();
//
//        if (pair2.second < roots.front()->get_data()->get_frequency()){
//            left = new Node(new Data(pair1.second, pair1.first));
//            right = new Node(new Data(pair2.second, pair2.first));
//            if (left->get_data()->get_frequency() < right->get_data()->get_frequency()){ //Gives the least frequent character the highest binary value
//                root = new Node(left, right);
//            }
//            else{
//                root = new Node(right, left);
//            }
//            freq_vect.pop_back();
//        }
//        else{
//            left = new Node(new Data(pair1.second, pair1.first));
//            root = new Node(left, roots.back());
//        }
//        roots.push_back(root);
//    }
    std::cout << root << endl;
}










