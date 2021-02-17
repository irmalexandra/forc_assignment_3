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

std::set<std::pair<char, int>, comp> make_frequency_table(std::vector<char> *file_content = nullptr);

void build_tree(std::set<std::pair<char, int>, comp> frequency_table);

void sort_map_values(std::map <char, int>& map_to_sort);
bool compare_values(int first, int second);

#endif //FORC_PA_3_HELPERFUNCTIONS_H
