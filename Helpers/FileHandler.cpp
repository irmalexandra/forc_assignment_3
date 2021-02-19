#include "FileHandler.h"


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

    //bitset<256>* encoding_key;
    int char_count = frequency_table->size();
    int length;
    FILE * output_file;
    output_file = fopen ("out_thing.txt", "wb");

    write_bytes_from_arr(key_map);

}

void write_bytes_from_arr(map<char, char*> *key_map){
    ofstream out_stream;
    char byte = 0;
    int count = 0;
    int keys_inserted = 0;
    int number_of_keys = key_map->size();
    cout << "Number of Keys: " << number_of_keys << endl;

    out_stream.open("test.txt", ios::out | ios::binary | ios::trunc);

    for (auto const& [key,value]:*key_map){

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

