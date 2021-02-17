#ifndef FORC_PA_3_DATA_H
#define FORC_PA_3_DATA_H

#include <iostream>

using namespace std;

class Data{
public:
    Data(int freq, char value = '\0');

    int get_frequency();

    char get_value();

    virtual ~Data()= default;

    friend ostream& operator<< (ostream& out, const Data *data);

private:
    int freq;
    char value;
};

#endif //FORC_PA_3_DATA_H
