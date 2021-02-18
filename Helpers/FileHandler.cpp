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
    }

    out_stream << byte;
    cout << "Byte written at end" << endl;
 /*
//    test_out.open("binary_test.txt", ios::out | ios::binary | ios::app);
//    int binary_value = 0;
//    for(int i = 0; i < strlen(arr); i++){
//        if(arr[i] == '0'){
//            binary_value = (binary_value << 1) + 0;
//            //test_out.write(0,1);
//        }
//        if(arr[i] == '1'){
//            binary_value = (binary_value << 1) + 1;
//            //test_out << write(1,1);
//        }
//    }
//    test_out << endl;

//    return binary_value;*/
}

