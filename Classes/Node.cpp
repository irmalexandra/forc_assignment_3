#include "Node.h"

Node::Node(Node *left, Node *right) {
    this->data = new Data((left->data->get_frequency() + right->data->get_frequency()));
    this->left = left;
    this->right = right;
}

Node::Node(Data *data) {
    this->data = data;
}

Node::~Node() {
    delete this->data;
    delete this->left;
    delete this ->right;
}

Data* Node::get_data() {
    return this->data;
}

ostream& operator<< (ostream& out, const Node *node){
    if(node != nullptr){
        out << node->data;
        out << node->left;
        out << node->right;
    }
    return out;
}
