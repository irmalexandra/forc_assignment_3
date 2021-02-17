#ifndef FORC_PA_3_NODE_H
#define FORC_PA_3_NODE_H
#include "Data.h"
#include "iostream"

using namespace std;

class Node{
public:
    Node(Node *left = nullptr, Node *right = nullptr);
    Node(Data *data = nullptr);

    Data* get_data();

    virtual ~Node();

    friend ostream& operator<< (ostream& out, const Node *node);

private:
    Data *data = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent;
};

#endif //FORC_PA_3_NODE_H
