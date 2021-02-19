

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



    out_stream.close();
}

void Compressor::write_bytes(ofstream& out_stream) {
    char byte = 0;
    int count = 0;
    int keys_inserted = 0;
    int number_of_keys = this->compression_info->key_map->size();
    cout << "Number of Keys: " << number_of_keys << endl;


    for (auto const& [key,value]:*this->compression_info->key_map){

        for (int i = 0; i < strlen(value); i++){
            if(count == 8){
                out_stream << byte;
                cout << "Byte Written" << endl;
                byte = 0;
                count = 0;

            }
            if (value[i] == '1'){
                if (keys_inserted == number_of_keys-1){
                    cout << "Count is : " << count << endl;
                    byte = byte | (1 << (7-count));
                    count++;

                }
                else{
                    byte = byte << 1;
                    byte = byte | 1;
                    count++;
                }

            }
            if(value[i] == '0'){
                if (keys_inserted == number_of_keys-1){
                    cout << "Count is : " << count << endl;
                    byte = byte | (0 << (7-count));
                    count++;
                }
                else{
                    byte = byte << 1;
                    count++;
                }

            }
        }
        keys_inserted++;

    }

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