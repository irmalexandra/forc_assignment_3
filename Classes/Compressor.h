

#ifndef FORC_PA_3_COMPRESSOR_H
#define FORC_PA_3_COMPRESSOR_H

#include "HuffmanEncoder.h"
#include "fstream"


class Compressor {
public:
    Compressor() = default;
    explicit Compressor(CompressionInfo* compression_info);
    ~Compressor();
    void compress();

private:
    CompressionInfo* compression_info;
    void write_bytes(ofstream& out_stream);
    void write_header(ofstream& out_stream);
};


#endif //FORC_PA_3_COMPRESSOR_H
