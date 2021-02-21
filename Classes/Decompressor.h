#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include "../Helpers/HelperFunctions.h"

#ifndef FORC_PA_3_HUFFMANENCODER_H
#define FORC_PA_3_ENCODER_H
#include "HuffmanDecoder.h"

using namespace std;

class Decompressor {

public:
    Decompressor() = default;
    explicit Decompressor(DecodeInfo* decode_info);
    ~Decompressor();
    void decompress(ifstream& in_stream,  ofstream& out_stream);

private:
    DecodeInfo* decode_info = nullptr;
};


#endif //FORC_PA_3_HUFFMANENCODER_H
