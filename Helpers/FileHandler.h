#ifndef FORC_PA_3_FILEHANDLER_H
#define FORC_PA_3_FILEHANDLER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <bitset>

using namespace std;

vector <char>* read_from_file(const string& filename);
void write_to_file(const string& filename, map<char, int> *frequency_table, map<char, char*> *key_map);
int convert_char_arr_to_binary(char* arr);
#endif //FORC_PA_3_FILEHANDLER_H
