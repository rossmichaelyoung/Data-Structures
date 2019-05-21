#include <iostream>
#include "UnsortedPQ.cpp"
#include "SortedPQ.cpp"
#include "HeapPQ.cpp"

using namespace std;

int main() {

    int num_elements;
    cout << "Enter number of elements to insert: ";
    cin >> num_elements;

    int *dataArray = new int [num_elements];
    for (int i = 0; i < num_elements; i++) {
        int data = rand() % 1000;
        cout << data << " ";
        dataArray[i] = data;
    }

    cout << endl;

    HeapPQ<int> *pq = new HeapPQ<int>(dataArray, num_elements);

    for (int i = 0; i < num_elements; i++) {
        cout << pq->removeMin() << " ";
    }
    delete pq;


    return 0;
}