#ifndef PROJECT_3_NODE_H
#define PROJECT_3_NODE_H

template <class T>
class Node {

public:
    Node<T> *next;
    Node<T> *previous;
    T data;
    explicit Node(T data) : next(nullptr), previous(nullptr), data(data) {}
};

#endif //PROJECT_3_NODE_H
