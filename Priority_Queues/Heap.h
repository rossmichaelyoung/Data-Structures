#ifndef PROJECT_3_HEAP_H
#define PROJECT_3_HEAP_H
#include "Node.h"
#include "KeyComparatorLT.h"

template <class T>
class Heap {

    Node<T>** arrayHeap;
    int n;
    KeyComparatorLT<T> *keyComparator;
    int arraySize;

public:
    Heap(int);
    ~Heap();
    void insert(T, int);
    void sortBottomUp();
    void sortTopDown();
    void swap(int, int);
    int least(int, int, int);
    Node<T>* min();
    T publicMin();
    void removeMin();
    int size();
    bool empty();
    void Print();
};

#endif //PROJECT_3_HEAP_H
