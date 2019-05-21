#include <iostream>
#include "NodeStack.h"
using namespace std;

template <class T>
NodeStack<T>::NodeStack() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
NodeStack<T>::~NodeStack() {
    Node<T> *current = this->head;
    while (current) {
        Node<T> *nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
    }
}

template <class T>
void NodeStack<T>::push(Node<T> *N) {

    if (head == nullptr) {
        head = N;
        tail = head;
    }

    else {
        N->next = head;
        head = N;
    }
}

template <class T>
int NodeStack<T>::size() {
    Node<T> *current = this->head;
    int i = 0;
    while (current) {
        current = current->next;
        i++;
    }
    return i;
}

template <class T>
void NodeStack<T>::pop() {
    Node<T> *current = this->head;
    head = head->next;
    delete current;
}

template <class T>
Node<T>* NodeStack<T>::top() {
    return head;
}

template <class T>
bool NodeStack<T>::empty() {
    if (head == nullptr)
        return true;

    else
        return false;
}