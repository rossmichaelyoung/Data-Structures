#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "Queue.h"

template <class T>
class arrayQueue : public AbstractQueue<T> {

private:
    int arraySize;
    int f;
    int r;
    int n;
    T *newArray;

public:
    arrayQueue(int);

    ~arrayQueue();

    bool empty();

    int size();

    T front();

    T dequeue();

    void enqueue (T);
};

#endif //ARRAYQUEUE_H