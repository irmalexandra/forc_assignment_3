//
// Created by emmik on 19/02/2021.
//

#include "HuffmanDecoder.h"

void HuffmanDecoder::populate_from_file(string file_name) {
    string myText;

    // Read from the text file
    ifstream MyReadFile(file_name, ios::in|ios::binary);
    MyReadFile.seekg(ios::beg);

    bool is_key = true;
    bool is_head = true;
    char key;
    deque<char> value;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        // cout << myText << endl;
        if(is_head){
            for(char & current_char : myText){
                if(is_head){
                    if(current_char == '\n' || current_char == '\r'){
                        this->key_map[key] = value;
                        is_key = true;
                        value.clear();
                    }
                    else if(is_key){
                        key = current_char;
                        is_key = false;
                    }
                    else if(current_char != ' '){
                        cout << current_char << " <--- " << endl;
                        value.push_back(myText[current_char]);
                    }
                }

                if(current_char == '\\'){
                    is_head = false;
                }
            }
        }
        else{
            this->compressed_strings.push_back(myText);
        }
    }
}

vector<string> HuffmanDecoder::get_compressed_strings() {
    return this->compressed_strings;
}

map<char, deque<char>> HuffmanDecoder::get_key_map() {
    return this->key_map;
}
