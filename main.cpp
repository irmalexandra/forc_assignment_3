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

        auto data = read_from_file(file_to_read);

        auto encoder = HuffmanEncoder();
        encoder.encode(data);
        auto encode_info = encoder.get_compression_info();

        auto compressor = Compressor(&encode_info);
        compressor.compress(output_file);

    }
    else{
        ifstream in_stream(file_to_read, ios::binary);
        auto decoder = HuffmanDecoder();

        decoder.decode(in_stream);
        auto decompressor = Decompressor(decoder.get_decode_info());
        ofstream out_stream(output_file, ios::binary);
        decompressor.decompress(in_stream, out_stream);

        in_stream.close();

    }


    return 0;
}
