#include "Data.h"

Data::Data(int freq, char value){
    this->freq = freq;
    this->value = value;
}
Data::Data(char value) {
    this->value = value;
}


ostream& operator<< (ostream& out, const Data *data){
    out << "f: " << data->freq;
    out << " | ";
    out << "v: " << data->value << endl;
    return out;
}

int Data::get_frequency() {
    return this->freq;
}

char Data::get_value() {
    return this->value;
}

Data::Data() {
    this->value = NULL;
    this->freq = NULL;
}

void Data::set_value(char value) {
    this->value = value;

}


