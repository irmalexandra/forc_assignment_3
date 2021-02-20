

#include "Compressor.h"

Compressor::Compressor(CompressionInfo* compression_info) {
    this->compression_info = compression_info;
}

Compressor::~Compressor() {
    delete this->compression_info;
}

void Compressor::compress() {
    ofstream out_stream;
    out_stream.open("test.txt", ios::binary|ios::trunc|ios::out);

    write_header(out_stream);
    write_bytes(out_stream);



    out_stream.close();
}

void Compressor::write_bytes(ofstream& out_stream) {
    char byte = 0;
    int byte_index = 0;
    int bytes_inserted = 0;
    int number_of_bytes = (this->compression_info->bit_count)/8;
    cout << "Number of Keys: " << number_of_bytes << endl;
    char* current_char;
    char* current_value;
    for(int x = 0; x < this->compression_info->file_content->size(); x++){

        current_char = &this->compression_info->file_content->at(x);

        if(*current_char != '\r' && *current_char != '\n'){
            cout << *current_char << " <-- curr char " << endl;
            current_value = (*this->compression_info->key_map)[*current_char];

            for (int i = 0; i < strlen(current_value); i++){
                if(byte_index == 8){
                    out_stream << byte;
                    bytes_inserted++;
                    cout << "Byte Written" << endl;
                    byte = 0;
                    byte_index = 0;

                }
                if (current_value[i] == '1'){
                    if (bytes_inserted == number_of_bytes){
                        cout << "Count is : " << byte_index << endl;
                        byte = byte | (1 << (7 - byte_index));
                        byte_index++;

                }
                else{
                    byte = byte << 1;
                    byte = byte | 1;
                    count++;
                }

                }
                if(current_value[i] == '0'){
                    if (bytes_inserted == number_of_bytes){
                        cout << "Count is : " << byte_index << endl;
                        byte = byte | (0 << (7 - byte_index));
                        byte_index++;
                    }
                    else{
                        byte = byte << 1;
                        byte_index++;
                    }
                }
            }
        }

    }
    delete current_char;
    delete current_value;


//    for (auto const& [key,value]:*this->compression_info->key_map){
//
//        for (int i = 0; i < strlen(value); i++){
//            if(byte_index == 8){
//                out_stream << byte;
//                cout << "Byte Written" << endl;
//                byte = 0;
//                byte_index = 0;
//
//            }
//            if (value[i] == '1'){
//                if (bytes_inserted == number_of_bytes-1){
//                    cout << "Count is : " << byte_index << endl;
//                    byte = byte | (1 << (7-byte_index));
//                    byte_index++;
//
//                }
//                else{
//                    byte = byte << 1;
//                    byte = byte | 1;
//                    byte_index++;
//                }
//
//            }
//            if(value[i] == '0'){
//                if (bytes_inserted == number_of_bytes-1){
//                    cout << "Count is : " << byte_index << endl;
//                    byte = byte | (0 << (7-byte_index));
//                    byte_index++;
//                }
//                else{
//                    byte = byte << 1;
//                    byte_index++;
//                }
//
//            }
//        }
//        bytes_inserted++;
//
//    }

    out_stream << byte;
    cout << "Byte written at end" << endl;
}

void Compressor::write_header(ofstream& out_stream) {
    cout << "FREQUENCY TABLE" << endl;
    for (auto data:*this->compression_info->frequency_table){
        cout << "Letter: " << data.first << endl;
        cout << "Frequency: " << data.second << endl;
    }


    cout << "KEY MAP" << endl;
    for (auto data:*this->compression_info->key_map){
        out_stream << data.first << " " << data.second << endl;

        cout << "Key : "<< data.first << endl;
        cout << "Value : " << data.second << endl;
    }

    cout << "NUMBER OF BITS" << endl;
    cout << this->compression_info->bit_count << endl;
    out_stream << this->compression_info->bit_count << endl;
    out_stream << "\\" << endl;
}