#ifndef PROJECT_3_SORTEDPQ_H
#define PROJECT_3_SORTEDPQ_H
#include "Node.h"

template <class T>
class SortedPQ {

    Node<T> *head;
    Node<T> *tail;
    int n;

public:
    SortedPQ ();
    ~SortedPQ ();
    bool empty ();
    int size ();
    void insert (T data);
    T removeMin ();
    T minValue ();
};



#endif //PROJECT_3_SORTEDPQ_H
