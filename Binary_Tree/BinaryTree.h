#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H
#include "Node.h"

template <class T>
class BinaryTree {

private:
    Node<T> *root;

public:
    BinaryTree();
    ~BinaryTree();
    void DeleteTree(Node<T> *leaf);
    void insert(T data, Node<T> *leaf);
    void insert(T data);
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
};

#endif //BINARY_TREE_BINARYTREE_H
