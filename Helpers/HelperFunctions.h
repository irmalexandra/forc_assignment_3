#ifndef FORC_PA_3_HELPERFUNCTIONS_H
#define FORC_PA_3_HELPERFUNCTIONS_H

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include "../Classes/Node.h"
#include "../Classes/Data.h"

//struct thing {
//    template <typename T>
//    // overload bool operator
//    bool operator()(const T& left, const T& right){
//        if (left.get_data().get_frequency() != right.get_data().get_frequency()) {
//            return left.get_data().get_frequency() > right.get_data().get_frequency();
//        }
//        return left.get_data().get_value() > right.get_data().get_value();
//    }
//};

map<char, int> make_frequency_table(std::vector<char> *file_content = nullptr);

Node* build_tree(map<char, int> frequency_table);

void make_compression_keys(Node *root);

#endif //FORC_PA_3_HELPERFUNCTIONS_H
