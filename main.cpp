#include <iostream>
#include <fstream>
#include <cstring>

#include "Classes/Node.h"
#include "Helpers/HelperFunctions.h"
#include "Helpers/FileHandler.h"



using namespace std;



int main(int argC, char *argv[]) {
    string file_to_read;
    bool decompress;
    string output_file;

    if(argC > 2){
        string stupif_stuff = argv[1];
        if(argv[1] == "-u"){
            decompress = true;
        }
        else{
            decompress = false;
        }
        file_to_read = argv[2];
        output_file = argv[3];
    }
    else{
        cout << "Enter file name: ";
        cin >> file_to_read;
    }


    if(!decompress){
        ifstream fileIn (file_to_read);
        auto data = read_from_file(file_to_read);

        auto frequency_table = make_frequency_table(data);
        auto root = build_tree(*frequency_table);
        map <char, char*>* key_map = make_compression_keys(root);
        string extension = "out.wav";
        string out_file_name = file_to_read.replace(file_to_read.size()-extension.size(), extension.size(), extension);
        write_to_file(out_file_name, frequency_table, key_map);

    }
    else{
        string myText;

        // Read from the text file
        ifstream MyReadFile(file_to_read, ios::in|ios::binary);
        MyReadFile.seekg(ios::beg);
        map<char, int> found_keys;
        vector<string> found_compressed_strings;
        bool is_key = true;
        bool is_head = true;
        char key;
        vector<char> value;
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (MyReadFile, myText)) {
            // Output the text from the file
            // cout << myText << endl;
            if(is_head){
                for(char & i : myText){
                    if(is_head){
                        if(i == '\n' || i == '\r'){
                            found_keys[key] = VectorToInt(value);
                            is_key = true;
                            value.clear();
                        }
                        else if(is_key){
                            key = i;
                            is_key = false;
                        }
                        else if(i != ' '){
                            value.push_back(i);
                        }
                    }

                    if(i == '\\'){
                        is_head = false;
                    }
                }
            }
            else{
                found_compressed_strings.push_back(myText);
            }
        }
    }


    return 0;
}
// 0x30 =  0 0 1 1 0 0 0 0
// 0x35 = 0 0 1 1 0 1 0 1
// 0x39 = 0 0 1 1 1 0 0 1