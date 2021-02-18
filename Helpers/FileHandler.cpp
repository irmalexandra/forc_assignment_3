#include "FileHandler.h"
#include <bitset>


vector <char>* read_from_file(const string& filename) {
    auto* data = new vector<char>();

    char byte;
    ifstream input_file(filename);
    while (input_file.get(byte)) {
        data->push_back(byte);
    }
    return data;
}

void write_to_file(const string& filename, map<char, int> *frequency_table, map<char, char*> *key_map) {

    bitset<256>* encoding_key;
    int char_count = frequency_table->size();
    int length;
    FILE * output_file;
    output_file = fopen ("out_thing.txt", "wb");

    for(auto const& [key, value]:*key_map){
        length = strlen(value);
        int binary_value = convert_char_arr_to_binary(value);
        encoding_key = new bitset<256>(binary_value);

        fwrite(value, 1, length, output_file);
//        for (int i = 0; i < length; i++){
//            output_file << encoding_key[i];
//        }
    }
//    output_file << '\\' << endl << endl;

    delete encoding_key;

}

