#include <iostream>
#include "HeapPQ.h"

using namespace std;

template <class T>
HeapPQ<T>::HeapPQ () {
    arraySize = 1000000;
    arrayHeap = new T [arraySize];
    n = 0;
}

template <class T>
HeapPQ<T>::HeapPQ (T *dataArray, int num_elements) {
    arrayHeap = dataArray;
    n = num_elements;
    arraySize = num_elements;

    if (num_elements > 1) {
        int i = n-1;

        if (i % 2 == 1) {
            int v = (i-1)/2;
            sortTopDown(v);
            i--;
        }

        while (i >= 1) {
            int v = (i-1)/2;
            sortTopDown(v);
            i -= 2;
        }
    }
}

template <class T>
HeapPQ<T>::~HeapPQ () {
    delete []arrayHeap;
}

template <class T>
bool HeapPQ<T>::empty () {
    return n == 0;
}

template <class T>
int HeapPQ<T>::size () {
    return n;
}

template <class T>
void HeapPQ<T>::insert (T data) {
    if (n+1 > arraySize)
        throw runtime_error("Priority Queue is full");

    n += 1;
    arrayHeap[n-1] = data;

    sortBottomUp();
}

template <class T>
T HeapPQ<T>::removeMin () {
    if (empty())
        throw runtime_error("Heap is empty");

    int minimumValue = arrayHeap[0];
    arrayHeap[0] = arrayHeap[n-1];
    n -= 1;

    sortTopDown(0);
    return minimumValue;
}

template <class T>
T HeapPQ<T>::minValue () {
    return arrayHeap[0];
}

template <class T>
void HeapPQ<T>::sortBottomUp () {
    for (int i = n-1; i >= 1; i = (i-1)/2) {
        int v = (i-1)/2;
        if (arrayHeap[i] < arrayHeap[v])
            swap(i, v);
    }
}

template <class T>
void HeapPQ<T>::sortTopDown (int index) {
    int i = index;

    while (2*i + 1 <= n-1) {
        int leftChild = (2*i) + 1;

        if (2*i + 2 <= n-1) {
            int rightChild = (2*i) + 2;

            if (arrayHeap[leftChild] < arrayHeap[i] && arrayHeap[rightChild] < arrayHeap[i]) {
                int v = least(i, leftChild, rightChild);
                swap(i, v);
                i = v;
            }

            else if (arrayHeap[leftChild] < arrayHeap[i]) {
                swap(i, leftChild);
                i = leftChild;
            }
            else if (arrayHeap[rightChild] < arrayHeap[i]) {
                swap(i, rightChild);
                i = rightChild;
            }
            else
                break;
        }
        else {
            if (arrayHeap[leftChild] < arrayHeap[i]) {
                swap(i, leftChild);
                i = leftChild;
            }
            else
                break;
        }
    }
}

template <class T>
void HeapPQ<T>::swap (int i, int v) {
    int temp = arrayHeap[v];
    arrayHeap[v] = arrayHeap[i];
    arrayHeap[i] = temp;
}

template <class T>
int HeapPQ<T>::least (int i, int leftChild, int rightChild) {
    int a = arrayHeap[i] - arrayHeap[leftChild];
    int b = arrayHeap[i] - arrayHeap[rightChild];

    if (a > b)
        return leftChild;
    else
        return rightChild;
}