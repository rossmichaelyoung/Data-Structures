#ifndef HOMEWORK_3_PRIORITYQUEUE_H
#define HOMEWORK_3_PRIORITYQUEUE_H
#include <list>
// Array of Lists

template <class T>
class PriorityQueue {

    std::list<T>* PQ;
    int arraySize;
    int num_elements;

public:
    PriorityQueue(int);
    ~PriorityQueue();
    int size();
    bool empty();
    void insert(int, T);
    T min();
    void removeMin();
    void Print();
};

#endif //HOMEWORK_3_PRIORITYQUEUE_H