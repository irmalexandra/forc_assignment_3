#ifndef FORC_PA_3_HELPERFUNCTIONS_H
#define FORC_PA_3_HELPERFUNCTIONS_H

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include "../Classes/Node.h"
#include "../Classes/Data.h"

map<char, int>* make_frequency_table(std::vector<char> *file_content = nullptr);
int VectorToInt(vector<char> v);
Node* build_tree(map<char, int> frequency_table);

map<char, char*>* make_compression_keys(Node *root);
bool comparer(Node* first, Node* second);

#endif //FORC_PA_3_HELPERFUNCTIONS_H
