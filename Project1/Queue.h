#ifndef ABSTRACT_QUEUE_H
#define ABSTRACT_QUEUE_H

template <class Type>
class AbstractQueue
{
private:
    // data goes here

public:
    AbstractQueue(void) {}

    ~AbstractQueue(void) {}

    bool empty(void) {}

    int size(void) {}

    Type front() {}

    Type dequeue() {}

    void enqueue ( Type e ) {}
};

#endif