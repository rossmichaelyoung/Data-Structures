#include <iostream>
#include <list>
#include <new>
#include "PriorityQueue.h"
using namespace std;
 // Array of Lists
 // removeMin() runs in O(k) because you need to check for first index that is not null

template <class T>
PriorityQueue<T>::PriorityQueue(int k) {
    arraySize = k + 1;
    PQ = new list<T> [arraySize];
    num_elements = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] PQ;
}

template <class T>
int PriorityQueue<T>::size() {
    return num_elements;
}

template <class T>
bool PriorityQueue<T>::empty() {
    return size() == 0;
}

template <class T>
void PriorityQueue<T>::insert(int key, T object) {
    PQ[key].push_back(object);
    num_elements++;
}

template <class T>
T PriorityQueue<T>::min() {
    for (int i = 0; i < arraySize; i++) {
        if (!PQ[i].empty())
            return PQ[i].front();
    }
}

template <class T>
void PriorityQueue<T>::removeMin() {
    for (int i = 0; i < arraySize; i++) {
        if (!PQ[i].empty()) {
            PQ[i].pop_front();
            break;
        }
    }
}

template <class T>
void PriorityQueue<T>::Print() {
    for (int i = 0; i < arraySize; i++) {
        if (!PQ[i].empty()) {
            cout << i << ": ";
            for (list<string>::iterator it = PQ[i].begin(); it != PQ[i].end(); ++it) {
                cout << *it << " ";
            }
        }
    }
}