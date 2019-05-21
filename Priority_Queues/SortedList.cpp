#include <stdexcept>
#include <iostream>
#include "SortedList.h"
using namespace std;

template <class T>
SortedList<T>::SortedList() {
    head = nullptr;
    tail = nullptr;
    n = 0;
}

template <class T>
SortedList<T>::~SortedList() {
    Node<T> *current = this->head;
    while (current) {
        Node<T> *DeleteNode = current;
        current = current->next;
        delete DeleteNode;
        DeleteNode = nullptr;
    }
}

template <class T>
void SortedList<T>::insert(T data, int key) {
    Node<T> *NewNode = new Node<T>(data, key);

    if (empty()) {
        head = NewNode;
        tail = NewNode;
    }

    else {
        Node<T> *current = this->head;

        while (current && keyComparator->operator()(current, NewNode)) {
            current = current->next;
        }

        if (current == head) {
            current->previous = NewNode;
            NewNode->next = current;
            head = NewNode;
        }

        else if (!current) {
            NewNode->previous = tail;
            tail->next = NewNode;
            tail = NewNode;
        }

        else {
            current->previous->next = NewNode;
            NewNode->previous = current->previous;
            NewNode->next = current;
            current->previous = NewNode;
        }
    }

    n++;
}

template <class T>
Node<T>* SortedList<T>::min() {
    if (empty())
        throw runtime_error ("Priority Queue is Empty");

    return head;
}

template <class T>
T SortedList<T>::publicMin() {
    return min()->data;
}

template <class T>
void SortedList<T>::removeMin() {
    Node<T>* DeleteNode = min();

    if (size() == 1) {
        delete DeleteNode;
        DeleteNode = nullptr;
    }

    else {
        head = head->next;
        head->previous = nullptr;
        delete DeleteNode;
        DeleteNode = nullptr;
    }

    n--;
}

template <class T>
void SortedList<T>::Print() {
    Node<T> *current = this->head;

    while (current) {
        cout << "(" << current->key << ", " << current->data << ")" << " ";
        current = current->next;
    }
    cout << endl;
}

template <class T>
int SortedList<T>::size() {
    return n;
}

template <class T>
bool SortedList<T>::empty() {
    return (n == 0);
}