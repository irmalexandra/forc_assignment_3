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
    ofstream output_file;
    output_file.open (filename, ios::out | ios::binary);

//    for(auto const& [key, value]:*key_map){
//        length = strlen(value);
//        encoding_key = new bitset<256>(stoi(value));
//        output_file << key << " ";
//        for (int i = 0; i < length; i++){
//            output_file << encoding_key[255-i];
//        }
//    }
    output_file << '\\' << endl << endl;

//    delete encoding_key;

}

