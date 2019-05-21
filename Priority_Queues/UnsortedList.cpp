#include <stdexcept>
#include <iostream>
#include "UnsortedList.h"
using namespace std;

template <class T>
UnsortedList<T>::UnsortedList() {
    head = nullptr;
    tail = nullptr;
    n = 0;
}

template <class T>
UnsortedList<T>::~UnsortedList() {
    Node<T> *current = this->head;
    while (current) {
        Node<T> *DeleteNode = current;
        current = current->next;
        delete DeleteNode;
        DeleteNode = nullptr;
    }
}

template <class T>
void UnsortedList<T>::insert(T data, int key) {
    Node<T> *NewNode = new Node<T>(data, key);

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
Node<T>* UnsortedList<T>::min() {
    if (empty())
        throw runtime_error ("Priority Queue is Empty");

    Node<T> *current = this->head;
    Node<T> *min = current;

    while (current) {
        if (keyComparator->operator()(current, min))
            min = current;

        current = current->next;
    }
    return min;
}

template <class T>
T UnsortedList<T>::publicMin() {
    return min()->data;
}

template <class T>
void UnsortedList<T>::removeMin() {
    Node<T> *DeleteNode = min();

    if (size() == 1) {
        DeleteNode = min();
        delete DeleteNode;
        DeleteNode = nullptr;
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
}

template <class T>
void UnsortedList<T>::Print() {
    Node<T> *current = this->head;

    while (current) {
        cout << "(" << current->key << ", " << current->data << ")" << " ";
        current = current->next;
    }
    cout << endl;
}

template <class T>
int UnsortedList<T>::size() {
    return n;
}

template <class T>
bool UnsortedList<T>::empty() {
    return (n == 0);
}