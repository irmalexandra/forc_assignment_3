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

struct comp {
    template <typename T>
    // overload bool operator
    bool operator()(const T& left, const T& right){
        if (left.second != right.second) {
            return left.second > right.second;
        }
        return left.first > right.first;
    }
};

std::set<std::pair<char, int>, comp> make_frequency_table(std::vector<char> *file_content = nullptr);

void build_tree(std::set<std::pair<char, int>, comp> frequency_table);

void sort_map_values(std::map <char, int>& map_to_sort);
bool compare_values(int first, int second);

#endif //FORC_PA_3_HELPERFUNCTIONS_H
