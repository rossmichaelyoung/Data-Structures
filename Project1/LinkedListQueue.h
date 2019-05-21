#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H
#include "Node.h"
#include "Queue.h"

template <class T>
class LinkedListQueue : public AbstractQueue<T> {

private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedListQueue();

    ~LinkedListQueue();

    bool empty();

    int size();

    T front();

    T dequeue();

    void enqueue (T);
};

#endif //LINKEDLISTQUEUE_H
