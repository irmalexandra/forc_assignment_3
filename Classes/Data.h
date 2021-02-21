#ifndef FORC_PA_3_DATA_H
#define FORC_PA_3_DATA_H

#include <iostream>

using namespace std;

class Data{
public:
    explicit Data();
    explicit Data(unsigned long freq, char value = '\0');
    explicit Data(char value);

    unsigned long get_frequency();
    void set_value(char value);

    char get_value();

    virtual ~Data()= default;

    friend ostream& operator<< (ostream& out, const Data *data);

private:
    unsigned long freq;
    char value;
};

#endif //FORC_PA_3_DATA_H
