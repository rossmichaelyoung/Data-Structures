#ifndef PROJECT_3_NODE_H
#define PROJECT_3_NODE_H

template <class T>
class Node {
public:
    Node<T> *next;
    Node<T> *previous;
    T data;
    int key;
    Node(T, int);
    Node(int);
};

template <class T>
Node<T>::Node(T data, int key) : next(nullptr), previous(nullptr), data(data), key(key) {}

template <class T>
Node<T>::Node(int key) : next(nullptr), previous(nullptr), data(0), key(key) {}

#endif //PROJECT_3_NODE_H