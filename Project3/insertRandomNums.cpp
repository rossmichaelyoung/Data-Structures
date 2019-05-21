#include <iostream>
#include "UnsortedPQ.cpp"
#include "SortedPQ.cpp"
#include "HeapPQ.cpp"
#include "stopwatch.h"
using namespace std;

int main() {

    int pqType;
    cout << "Enter Priority Queue Type Number: ";
    cin >> pqType;

    int num_elements;
    cout << "Enter number of elements to insert: ";
    cin >> num_elements;

    cout << endl;

    srand(time(0));

    if (pqType >= 0 && pqType < 3) {
        cout << "Time for every 100 insertions: " << endl;

        if (pqType == 0) {
            UnsortedPQ<int> *pq = new UnsortedPQ<int>;
            CStopWatch pqClock;

            for (int i = 0; i < num_elements; i++) {
                pq->insert(rand() % 1000);

                if (i % 1000 == 0)
                    cout << pqClock.GetElapsedSeconds() << endl;
            }

            for (int i = 0; i < num_elements; i++) {
                pq->removeMin();
            }

            cout << endl;
            cout << "Time to insert and remove all elements: " << pqClock.GetElapsedSeconds() << endl;

            delete pq;
        }

        else if (pqType == 1) {
            SortedPQ<int> *pq = new SortedPQ<int>;
            CStopWatch pqClock;

            for (int i = 0; i < num_elements; i++) {
                pq->insert(rand() % 1000);

                if (i % 100 == 0)
                    cout << pqClock.GetElapsedSeconds() << endl;
            }

            for (int i = 0; i < num_elements; i++) {
                pq->removeMin();
            }

            cout << endl;
            cout << "Time to insert and remove all elements: " << pqClock.GetElapsedSeconds() << endl;

            delete pq;
        }

        else if (pqType == 2) {
            HeapPQ<int> *pq = new HeapPQ<int>();
            CStopWatch pqClock;

            for (int i = 0; i < num_elements; i++) {
                pq->insert(rand() % 1000);

                if (i % 10000 == 0)
                    cout << pqClock.GetElapsedSeconds() << endl;
            }

            for (int i = 0; i < num_elements; i++) {
                pq->removeMin();
            }

            cout << endl;
            cout << "Time to insert and remove all elements: " << pqClock.GetElapsedSeconds() << endl;

            delete pq;
        }
    }

    else if(pqType == 3) {
        int *dataArray = new int [num_elements];
        for (int i = 0; i < num_elements; i++) {
            int data = rand() % 1000;
            dataArray[i] = data;
        }
        CStopWatch pqClock;

        HeapPQ<int> *pq = new HeapPQ<int>(dataArray, num_elements);

        cout << "Time to insert " << num_elements << " elements: " << pqClock.GetElapsedSeconds() << endl;

        delete pq;
    }

    else
        throw runtime_error("Unable to determine priority queue type");

    return 0;
}