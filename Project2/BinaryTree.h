#ifndef PROJECT_2_BINARYTREE_H
#define PROJECT_2_BINARYTREE_H
#include "Node.h"

template <class T>
class BinaryTree {

    Node<T> *root;
    int height;
    Node<T>* insert(T, Node<T>*);
    void DeleteTree(Node<T>*);

public:
    BinaryTree();
    ~BinaryTree();
    void PublicInsert(T);
    int TreeHeight();
};

#endif //PROJECT_2_BINARYTREE_H