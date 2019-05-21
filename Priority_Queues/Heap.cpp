#include <iostream>
#include <stdexcept>
#include "Heap.h"
using namespace std;

template <class T>
Heap<T>::Heap(int size) {
    arraySize = size;
    arrayHeap = new Node<T>* [arraySize];
    n = 0;
}

template <class T>
Heap<T>::~Heap() {
    delete []arrayHeap;
}

template <class T>
void Heap<T>::insert(T data, int key) {
    Node<T>* NewNode = new Node<T>(data, key);

    if (n+1 > arraySize)
        arrayHeap[n-1] = NewNode;

    else {
        n += 1;
        arrayHeap[n-1] = NewNode;
    }

    sortBottomUp();
}

template <class T>
void Heap<T>::sortBottomUp() {
    for (int i = n-1; i >= 1; i = (i-1)/2) {
        int v = (i-1)/2;
        if (keyComparator->operator()(arrayHeap[i], arrayHeap[v]))
            swap(i, v);
    }
}

template <class T>
void Heap<T>::sortTopDown() {
    int i = 0;

    while (2*i + 1 <= n-1) {
        int leftChild = (2*i) + 1;

        if (2*i + 2 <= n-1) {
            int rightChild = (2*i) + 2;

            if (keyComparator->operator()(arrayHeap[leftChild], arrayHeap[i]) &&
                keyComparator->operator()(arrayHeap[rightChild], arrayHeap[i])) {
                int v = least(i, leftChild, rightChild);
                swap(i, v);
                i = v;
            }

            else if (keyComparator->operator()(arrayHeap[leftChild], arrayHeap[i])) {
                swap(i, leftChild);
                i = leftChild;
            }
            else if (keyComparator->operator()(arrayHeap[rightChild], arrayHeap[i])) {
                swap(i, rightChild);
                i = rightChild;
            }
            else
                break;
        }
        else {
            if (keyComparator->operator()(arrayHeap[leftChild], arrayHeap[i])) {
                swap(i, leftChild);
                i = leftChild;
            }
            else
                break;
        }
    }
}

template <class T>
int Heap<T>::least(int i, int leftChild, int rightChild) {
    int a = arrayHeap[i]->key - arrayHeap[leftChild]->key;
    int b = arrayHeap[i]->key - arrayHeap[rightChild]->key;

    if (a > b)
        return leftChild;
    else
        return rightChild;
}

template <class T>
void Heap<T>::swap(int i, int v) {
    Node<T>* temp = arrayHeap[v];
    arrayHeap[v] = arrayHeap[i];
    arrayHeap[i] = temp;
}

template <class T>
Node<T>* Heap<T>::min() {
    return arrayHeap[0];
}

template <class T>
T Heap<T>::publicMin() {
    return arrayHeap[0]->data;
}

template <class T>
void Heap<T>::removeMin() {
    if (empty())
        throw runtime_error("Heap is empty");

    arrayHeap[0] = arrayHeap[n-1];
    n -= 1;

    sortTopDown();
}

template <class T>
int Heap<T>::size() {
    return n;
}

template <class T>
bool Heap<T>::empty() {
    return n == 0;
}

template <class T>
void Heap<T>::Print() {
    for (int i = 0; i < n; i++)
        cout << "(" << arrayHeap[i]->key << ", " << arrayHeap[i]->data << ")" << " ";
    cout << endl;
}