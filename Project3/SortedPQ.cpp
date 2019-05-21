#include <iostream>
#include "SortedPQ.h"

using namespace std;


template <class T>
SortedPQ<T>::SortedPQ () {
    head = nullptr;
    tail = nullptr;
    n = 0;
}

template <class T>
SortedPQ<T>::~SortedPQ () {
    Node<T> *current = this->head;
    while (current) {
        Node<T> *DeleteNode = current;
        current = current->next;
        delete DeleteNode;
        DeleteNode = nullptr;
    }
}

template <class T>
bool SortedPQ<T>::empty () {
    return n == 0;
}

template <class T>
int SortedPQ<T>::size () {
    return n;
}

template <class T>
void SortedPQ<T>::insert (T data) {
    Node<T> *NewNode = new Node<T>(data);

    if (empty()) {
        head = NewNode;
        tail = NewNode;
    }

    else {
        Node<T> *current = tail;

        while (current && (NewNode->data < current->data)) {
            current = current->previous;
        }

        if (current == tail) {
            tail->next = NewNode;
            NewNode->previous = tail;
            tail = NewNode;
        }

        else if (!current) {
            NewNode->next = head;
            head->previous = NewNode;
            head = NewNode;
        }

        else {
            current->next->previous = NewNode;
            NewNode->previous = current;
            NewNode->next = current->next;
            current->next = NewNode;
        }
    }

    n++;
}

template <class T>
T SortedPQ<T>::removeMin () {
    Node<T>* DeleteNode = head;
    int minimumValue = DeleteNode->data;

    if (size() == 1) {
        delete DeleteNode;
        DeleteNode = nullptr;
        head = nullptr;
        tail = nullptr;
    }

    else {
        head = head->next;
        head->previous = nullptr;
        delete DeleteNode;
        DeleteNode = nullptr;
    }

    n--;
    return minimumValue;
}

template <class T>
T SortedPQ<T>::minValue () {
    if (empty())
        throw runtime_error ("Priority Queue is Empty");

    return head->data;
}