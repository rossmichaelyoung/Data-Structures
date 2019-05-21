#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template <class T>
class Node {

public:
    T data;
    Node<T> *parent;
    Node<T> *right;
    Node<T> *left;
    Node() : left(nullptr), right(nullptr), parent(nullptr) {}
};

#endif //BINARY_TREE_NODE_H
