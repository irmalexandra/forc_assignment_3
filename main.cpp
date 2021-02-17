#include <iostream>
#include <fstream>
#include <cstring>

#include "Classes/Node.h"
#include "Helpers/FileHandler.h"
#include "Helpers/HelperFunctions.h"

using namespace std;

int main(int argC, char *argv[]) {
    string file_to_read;

    if(argC == 2){
        file_to_read = argv[1];
    }
    else{
        cout << "Enter file name: ";
        cin >> file_to_read;
    }

    ifstream fileIn (file_to_read);
    auto data = read_from_file(file_to_read);
    auto frequency_table = make_frequency_table(data);
    build_tree(frequency_table);
//    for(const auto& [key, value] : frequency_table){
//        cout << key << " = " << value << endl;
//    }

    Node* my_node = new Node(new Data(100, 'k'));



    return 0;
}
