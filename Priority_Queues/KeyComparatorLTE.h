#ifndef PROJECT_3_KEYCOMPARATORLTE_H
#define PROJECT_3_KEYCOMPARATORLTE_H
#include "Node.h"

template <class T>
class KeyComparatorLTE {

public:
    KeyComparatorLTE() {}
    bool operator()(Node<T>* n, Node<T>* k) { return n->key <= k->key; }
};

#endif //PROJECT_3_KEYCOMPARATORLTE_H
