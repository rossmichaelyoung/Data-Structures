#ifndef PROJECT_3_UNSORTEDPQ_H
#define PROJECT_3_UNSORTEDPQ_H
#include "Node.h"

template <class T>
class UnsortedPQ {

    Node<T> *head;
    Node<T> *tail;
    int n;

public:
    UnsortedPQ ();
    ~UnsortedPQ ();
    bool empty ();
    int size ();
    void insert (T data);
    T removeMin ();
    T minValue ();
};

#endif //PROJECT_3_UNSORTEDPQ_H