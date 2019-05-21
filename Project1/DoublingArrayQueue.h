#ifndef DOUBLEARRAYQUEUE_H
#define DOUBLEARRAYQUEUE_H
#include "Queue.h"

template <class T>
class DoublingArrayQueue : public AbstractQueue<T> {

private:
    int arraySize;
    int f;
    int r;
    int n;
    T *newArray;

public:
    DoublingArrayQueue(int);

    ~DoublingArrayQueue();

    bool empty();

    int size();

    T front();

    T dequeue();

    void enqueue (T);
};

#endif //DOUBLEARRAYQUEUE_H
