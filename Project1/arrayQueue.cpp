#include <stdexcept>
#include <iostream>
#include "arrayQueue.h"
using namespace std;

template <class T>
arrayQueue<T>::arrayQueue (int arraySize) : arraySize(arraySize) {
    newArray = new T [arraySize];
    f = 0;
    r = 0;
    n = 0;
}

template <class T>
arrayQueue<T>::~arrayQueue() {
    delete newArray;
}

template <class T>
int arrayQueue<T>::size() {
    return n;
}

template <class T>
bool arrayQueue<T>::empty() {
    if (size() == 0)
        return true;
    else
        return false;
}

template <class T>
T arrayQueue<T>::front() {
    if (empty()) {
        throw runtime_error ("Queue is empty");
    }

    return newArray[f];
}

template <class T>
T arrayQueue<T>::dequeue() {
    if (empty()) {
        throw runtime_error ("Queue is empty");
    }

    else {
        //increment f and allow f the ability to wrap around array if needed
        f = (f + 1) % arraySize;
        n = n - 1;
        return newArray[f];
    }
}

template <class T>
void arrayQueue<T>::enqueue(T data) {

    //increments size of array
    if (size() == arraySize) {
        T *newerArray = new T [arraySize + 50];

        //ensuring new array is organized from f = 0 to r = arraySize of old array
        if (r > 0) {
            int i = f;
            int k = 0;
            while (i != (r - 1)) {
                newerArray[k] = newArray[i];
                k++;
                i = (i + 1) % arraySize;
            }

            //ensuring data at index r-1 is at the end of the new array
            newerArray[arraySize - 1] = newArray[r - 1];

            //reindexing f
            f = 0;
        }
        else {
            for (int i = 0; i < arraySize; i++) {
                newerArray[i] = newArray[i];
            }
        }

        //reindexing r to be at the end of the new array
        r = arraySize;

        arraySize += 50;
        delete newArray;
        newArray = newerArray;
    }

    if (empty()) {
        f = 0;
        r = 0;
    }

    newArray[r] = data;

    //increment r and allow r the ability to wrap around array if needed
    r = (r + 1) % arraySize;
    n = n + 1;
}
