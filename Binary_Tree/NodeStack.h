#ifndef BINARY_TREE_NODESTACK_H
#define BINARY_TREE_NODESTACK_H
#include "Node.h"

template <class T>
class NodeStack {

    Node<T> *head;
    Node<T> *tail;

public:

    NodeStack();
    ~NodeStack();
    void push(Node<T> *N);
    void pop();
    int size();
    Node<T>* top();
    bool empty();
};



#endif //BINARY_TREE_NODESTACK_H
