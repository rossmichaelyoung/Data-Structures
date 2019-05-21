#ifndef PROJECT_3_SORTEDLIST_H
#define PROJECT_3_SORTEDLIST_H
#include "Node.h"
#include "KeyComparatorLTE.h"

template <class T>
class SortedList {

    Node<T> *head;
    Node<T> *tail;
    KeyComparatorLTE<T> *keyComparator;
    int n;

public:
    SortedList();
    ~SortedList();
    void insert(T, int);
    Node<T>* min();
    T publicMin();
    void removeMin();
    int size();
    bool empty();
    void Print();
};

#endif //PROJECT_3_SORTEDLIST_H