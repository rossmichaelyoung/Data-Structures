#ifndef PROJECT_3_COMPARATOR_H
#define PROJECT_3_COMPARATOR_H
#include "Node.h"

template <class T>
class KeyComparatorLT {

public:
    KeyComparatorLT() {}
    bool operator()(Node<T>* n, Node<T>* k) { return n->key < k->key; }
};

#endif //PROJECT_3_COMPARATOR_H