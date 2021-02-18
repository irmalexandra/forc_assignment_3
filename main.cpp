#include <iostream>
#include <fstream>
#include <cstring>

#include "Classes/Node.h"
#include "Helpers/HelperFunctions.h"
#include "Helpers/FileHandler.h"



using namespace std;

int main(int argC, char *argv[]) {
    string file_to_read;

    if(argC == 2){
        file_to_read = argv[1];
    }
    else{
        cout << "Enter file name: ";
        cin >> file_to_read;
    }

    ifstream fileIn (file_to_read);
    auto data = read_from_file(file_to_read);

    auto frequency_table = make_frequency_table(data);
    auto root = build_tree(*frequency_table);
    map <char, char*>* key_map = make_compression_keys(root);
    string extension = "out.wav";
    string out_file_name = file_to_read.replace(file_to_read.size()-extension.size(), extension.size(), extension);
    write_to_file(out_file_name, frequency_table, key_map);

    return 0;
}
