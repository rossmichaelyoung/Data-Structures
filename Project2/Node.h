#ifndef PROJECT_2_NODE_H
#define PROJECT_2_NODE_H

template <class T>
class Node {

public:
    T data;
    int depth;
    Node<T> *right;
    Node<T> *left;
    Node<T> *parent;
    explicit Node(T);
};

template<class T>
Node<T>::Node(T data) : right(nullptr), left(nullptr), parent(nullptr), data(data) {}

#endif //PROJECT_2_NODE_H