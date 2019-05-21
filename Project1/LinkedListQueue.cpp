#include <iostream>
#include <stdexcept>
#include "LinkedListQueue.h"
using namespace std;

template <class T>
LinkedListQueue<T>::LinkedListQueue() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedListQueue<T>::~LinkedListQueue() {
    Node<T> *current = this->head;
    while (current) {
        Node<T> *NodeToDelete = current;
        current = current->next;
        delete NodeToDelete;
    }
    delete current;
}

template <class T>
bool LinkedListQueue<T>::empty() {
    if (size() == 0)
        return true;
    else
        return false;
}

template <class T>
int LinkedListQueue<T>::size() {
    Node<T> *current = this->head;

    if (head == nullptr)
        return 0;

    else {
        int i = 0;
        while (current) {
            i++;
            current = current->next;
        }
        return i;
    }
}

template <class T>
T LinkedListQueue<T>::front() {
    if (empty())
        throw runtime_error("Queue is empty");
    else
        return head->data;
}

template <class T>
T LinkedListQueue<T>::dequeue() {
    if (empty())
        throw runtime_error("Queue is empty");
    else {
        Node<T> *current = this->head;
        head = head->next;
        delete current;

        if (size() == 0)
            return 0;
        else
            return head->data;
    }
}

template <class T>
void LinkedListQueue<T>::enqueue (T data) {
    Node<T> *newNode = new Node<T>;
    newNode->data = data;

    if (head == nullptr) {
        head = newNode;
        tail = head;
    }

    else {
        tail->next = newNode;
        tail = newNode;
    }
}