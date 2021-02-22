//
// Created by emmik on 19/02/2021.
//

#include "HuffmanDecoder.h"

HuffmanDecoder::~HuffmanDecoder() {

    delete this->file_content;
//    if(this->root){ TODO: fix?
//        delete this->root;
//
//    }
//    delete this->compression_keys;
//    delete this->bit_count;
}

void HuffmanDecoder::decode(ifstream &stream){
    read_head(stream);
    make_decode_tree();
}

void HuffmanDecoder::build_tree_from_keys(deque<char> value, char key, Node* current_node){
    if(value.empty()){
        auto data = new Data(key);
        current_node->set_data(data);
        return;
    }

    if(value[0] == '1'){
        value.pop_front();
        if(current_node->get_right() == nullptr){
            current_node->set_right(new Node);
        }
        build_tree_from_keys(value, key, current_node->get_right());
    }

    else if(value[0] == '0'){
        value.pop_front();
        if(current_node->get_left() == nullptr){
            current_node->set_left(new Node);
        }
        build_tree_from_keys(value, key, current_node->get_left());
    }
}

void HuffmanDecoder::make_decode_tree() {
    this->root = new Node;
    for(const auto& pair : *this->compression_keys){
        build_tree_from_keys(pair.second, pair.first, this->root);
    }

}

DecodeInfo*::HuffmanDecoder::get_decode_info() {
    return new DecodeInfo(this->compression_keys, this->bit_count, this->root);
}

void HuffmanDecoder::read_head(ifstream &stream) {

    bool is_key = true;
    char key;
    int value_length;
    char current_char;
    this->compression_keys = new map<char, deque<char>>;
    vector<char> bit_count;
    deque<char> value;
    vector<char> key_container;

    current_char = (char)stream.get();
    while(current_char != '\n'){
        key_container.push_back(current_char);
        current_char = (char) stream.get();
    }
    int number_of_keys = stoi(string(key_container.begin(), key_container.end()));

    current_char = (char) stream.get();

    if(number_of_keys == 0){
        number_of_keys = 256;
    }
    for(int i = 0; i < number_of_keys; i++){

        key = current_char;
        current_char = (char) stream.get();

        value_length = current_char;
        current_char = (char) stream.get();
        if(i = 145){
            cout;
        }

        for(int x = 0; x < value_length; x++){
            bool thing = current_char & (1 << 7 - x);
            if(thing){
                value.push_back('1');
            }
            else{
                value.push_back('0');
            }
            if(x % 8 == 0 && x != 0){
                current_char = (char) stream.get();
            }
        }
        this->compression_keys->insert(pair<char, deque<char>>(key, value));
        value.clear();
        current_char = (char) stream.get();

    }

    while(current_char != '\\'){
        bit_count.push_back(current_char);
        current_char = (char) stream.get();
    }

    this->bit_count = new int(stoi(string(bit_count.begin(),bit_count.end())));

//
//    while (!stream.eof()) {
//        current_char = (char)stream.get();
//
//        if(is_head){
//            if(is_key){
//                key = current_char;
//                is_key = false;
//            }
//            else if(current_char == '\n'){
//                this->compression_keys->insert(pair<char, deque<char>>(key, value));
//                is_key = true;
//                value.clear();
//            }
//            else if(current_char != ' '){
//                value.push_back(current_char);
//            }
//        }
//        else if(is_bit_count){
//            bit_count.push_back(current_char);
//        }
//
//        if(current_char == '\\' && is_head){
//            auto position = stream.tellg();
//            if((char)stream.get() == '\n'){
//                is_head = false;
//                is_bit_count = true;
//            }
//            stream.seekg(position);
//
//        }
//        else if(current_char == '\\'){
//            break;
//        }
//    }
//    this->bit_count = new int(stoi(string(bit_count.begin(),bit_count.end())));

}


//void HuffmanDecoder::read_head(ifstream &stream) {
//
//    bool is_key = true;
//    bool is_head = true;
//    bool is_bit_count = false;
//    char key;
//    char current_char;
//    this->compression_keys = new map<char, deque<char>>;
//    vector<char> bit_count;
//    deque<char> value;
//
//    // Use a while loop together with the getline() function to read the file line by line
//    while (!stream.eof()) {
//        current_char = (char)stream.get();
//
//        if(is_head){
//            if(is_key){
//                key = current_char;
//                is_key = false;
//            }
//            else if(current_char == '\n'){
//                this->compression_keys->insert(pair<char, deque<char>>(key, value));
//                is_key = true;
//                value.clear();
//            }
//            else if(current_char != ' '){
//                value.push_back(current_char);
//            }
//        }
//        else if(is_bit_count){
//            bit_count.push_back(current_char);
//        }
//
//        if(current_char == '\\' && is_head){
//            auto position = stream.tellg();
//            if((char)stream.get() == '\n'){
//                is_head = false;
//                is_bit_count = true;
//            }
//            stream.seekg(position);
//
//        }
//        else if(current_char == '\\'){
//            break;
//        }
//    }
//    this->bit_count = new int(stoi(string(bit_count.begin(),bit_count.end())));
//}

