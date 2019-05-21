#include <iostream>
#include <fstream>
#include "UnsortedPQ.cpp"
#include "SortedPQ.cpp"
#include "HeapPQ.cpp"

using namespace std;

int main() {

    string input_file;
    cout << "Enter file name: ";
    cin >> input_file;

    ifstream ifs = ifstream(input_file);

    if (ifs.is_open()) {
        int pqType;
        int num_elements;
        ifs >> pqType;
        ifs >> num_elements;

        if (pqType == 0) {
            UnsortedPQ<int> *pq = new UnsortedPQ<int>;

            for (int i = 0; i < num_elements; i++) {
                int data;
                ifs >> data;
                pq->insert(data);
            }

            for (int i = 0; i < num_elements; i++) {
                cout << pq->removeMin() << " ";
            }
            delete pq;
        }

        else if (pqType == 1) {
            SortedPQ<int> *pq = new SortedPQ<int>;

            for (int i = 0; i < num_elements; i++) {
                int data;
                ifs >> data;
                pq->insert(data);
            }

            for (int i = 0; i < num_elements; i++) {
                cout << pq->removeMin() << " ";
            }
            delete pq;
        }

        else if (pqType == 2) {
            HeapPQ<int> *pq = new HeapPQ<int>();

            for (int i = 0; i < num_elements; i++) {
                int data;
                ifs >> data;
                pq->insert(data);
            }

            for (int i = 0; i < num_elements; i++) {
                cout << pq->removeMin() << " ";
            }
            delete pq;
        }

        else
            throw runtime_error("Unable to determine priority queue type");
    }

    else
        throw runtime_error("Unable to open file");

    return 0;
}