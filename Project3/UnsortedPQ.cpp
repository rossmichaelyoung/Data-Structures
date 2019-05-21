#include <iostream>
#include "UnsortedPQ.h"

using namespace std;

template <class T>
UnsortedPQ<T>::UnsortedPQ () {
    head = nullptr;
    tail = nullptr;
    n = 0;
}

template <class T>
UnsortedPQ<T>::~UnsortedPQ () {
    Node<T> *current = this->head;
    while (current) {
        Node<T> *DeleteNode = current;
        current = current->next;
        delete DeleteNode;
        DeleteNode = nullptr;
    }
}

template <class T>
bool UnsortedPQ<T>::empty () {
    return n == 0;
}

template <class T>
int UnsortedPQ<T>::size () {
    return n;
}

template <class T>
void UnsortedPQ<T>::insert (T data) {
    Node<T> *NewNode = new Node<T>(data);

    if (empty()) {
        head = NewNode;
        tail = NewNode;
    }

    else {
        tail->next = NewNode;
        NewNode->previous = tail;
        tail = NewNode;
    }

    n++;
}

template <class T>
T UnsortedPQ<T>::removeMin () {
    if (empty())
        throw runtime_error ("Priority Queue is Empty");

    Node<T> *current = head;
    Node<T> *min = current;

    while (current) {
        if (current->data < min->data)
            min = current;

        current = current->next;
    }

    Node<T> *DeleteNode = min;
    int minimumValue = DeleteNode->data;

    if (size() == 1) {
        delete DeleteNode;
        DeleteNode = nullptr;
        head = nullptr;
        tail = nullptr;
    }

    else {
        if (DeleteNode == head) {
            head = head->next;
            head->previous = nullptr;
        }

        else if (DeleteNode == tail) {
            tail = tail->previous;
            tail->next = nullptr;
        }

        else {
            DeleteNode->previous->next = DeleteNode->next;
            DeleteNode->next->previous = DeleteNode->previous;
        }

        delete DeleteNode;
        DeleteNode = nullptr;
    }

    n--;
    return minimumValue;
}

template <class T>
T UnsortedPQ<T>::minValue () {
    if (empty())
        throw runtime_error ("Priority Queue is Empty");

    Node<T> *current = this->head;
    Node<T> *min = current;

    while (current) {
        if (current->data < min->data)
            min = current;

        current = current->next;
    }
    return min->data;
}