

#include "Compressor.h"

Compressor::Compressor(EncodeInfo* compression_info) {
    this->compression_info = compression_info;
}

Compressor::~Compressor() {
    delete[] this->compression_info;
}

void Compressor::compress(string file_name) {
    ofstream out_stream;
    out_stream.open(file_name, ios::binary|ios::trunc|ios::out);

    write_header(out_stream);
    write_bytes(out_stream);

    out_stream.close();
}

void Compressor::set_bit(char& byte, char& bit_char, int& byte_index, bool is_overflow){
    if (bit_char == '1'){
        if (is_overflow){
            byte = byte | (1 << (7 - byte_index));
        }
        else{
            byte = byte << 1;
            byte = byte | 1;
        }
    }
    if(bit_char == '0'){
        if (is_overflow){
            byte = byte | (0 << (7 - byte_index));
        }
        else{
            byte = byte << 1;
        }
    }
}

void Compressor::write_bytes(ofstream& out_stream) {
    char byte = 0;
    int byte_index = 0;
    int bytes_inserted = 0;
    int number_of_bytes = (this->compression_info->bit_count)/8;
    char* current_char;
    char* current_value;
    for(int x = 0; x < this->compression_info->file_content->size(); x++){

        current_char = &this->compression_info->file_content->at(x);
        current_value = (*this->compression_info->compression_keys)[*current_char];

        for (int i = 0; i < strlen(current_value); i++){
            set_bit(byte, current_value[i], byte_index, bytes_inserted == number_of_bytes);
            byte_index++;
            if(byte_index == 8){
                out_stream << byte;
                bytes_inserted++;
                byte = 0;
                byte_index = 0;
            }
        }

    }
    delete current_char;
    delete current_value;

    out_stream << byte;
}

void Compressor::write_header(ofstream& out_stream) {
    for (auto data:*this->compression_info->compression_keys){
        out_stream << data.first << " " << data.second << endl;
    }

    out_stream << "\\" << endl;
    out_stream << this->compression_info->bit_count << endl;
    out_stream << "\\" << endl;
}
void Compressor::write_header2(ofstream& out_stream) {
    int bytes_needed = 0;
    for (auto data:*this->compression_info->compression_keys){
        bytes_needed = strlen(data.second)/8;
        out_stream << data.first << " ";
        for (int i = 0; i < strlen(data.second); i++){

        }
    }

    out_stream << "\\" << endl;
    out_stream << (long)this->compression_info->bit_count << endl;
    out_stream << "\\" << endl;
}