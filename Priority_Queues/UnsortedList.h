#ifndef PROJECT_3_UNSORTEDLIST_H
#define PROJECT_3_UNSORTEDLIST_H
#include "Node.h"
#include "KeyComparatorLT.h"

template <class T>
class UnsortedList {

    Node<T> *head;
    Node<T> *tail;
    KeyComparatorLT<T> *keyComparator;
    int n;

public:
    UnsortedList();
    ~UnsortedList();
    void insert(T, int);
    Node<T>* min();
    T publicMin();
    void removeMin();
    int size();
    bool empty();
    void Print();
};

#endif //PROJECT_3_UNSORTEDLIST_H