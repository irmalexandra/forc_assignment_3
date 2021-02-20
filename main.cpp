#include <iostream>
#include "Classes/Decompressor.h"
#include "Classes/Node.h"
#include "Classes/HuffmanDecoder.h"
#include "Classes/HuffmanEncoder.h"
#include "Classes/HuffmanEncoder.h"
#include "Helpers/HelperFunctions.h"
#include "Helpers/FileHandler.h"
#include "Classes/Compressor.h"

using namespace std;



int main(int argC, char *argv[]) {
    string file_to_read;
    bool uncompress;
    string output_file;

    if(argC > 2){

        if((string) argv[1] == "-u" || (string) argv[1] == "-U"){
            uncompress = true;
        }
        else if((string) argv[1] == "-c" || (string) argv[1] == "-C"){
            uncompress = false;
        }
        else{
            cout << "ERROR: UNKNOWN ARGUMENT" << endl;
            return -1;
        }
        file_to_read = argv[2];
        output_file = argv[3];
    }
    else{
        cout << "Enter file name: ";
        cin >> file_to_read;
    }


    if(!uncompress){
//        ifstream fileIn (file_to_read);
        auto data = read_from_file(file_to_read);

        auto encoder = new HuffmanEncoder(data);

        encoder->make_frequency_table();
        encoder->build_tree();
        encoder->make_compression_keys();
        auto compression_info = encoder->get_compression_info();

        auto compressor = Compressor(&compression_info);
        compressor.compress();

        /*string extension = "out.wav";
        string out_file_name = file_to_read.replace(file_to_read.size()-extension.size(), extension.size(), extension);
        write_to_file(out_file_name, compression_info.frequency_table, compression_info.key_map);*/

    }
    else{
        auto * decompressor = new Decompressor;
        auto * decoder = new HuffmanDecoder;
        decoder->populate_from_file(file_to_read);
        decompressor->build_key_tree(decoder->get_key_map());
    }


    return 0;
}
