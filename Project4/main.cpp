#include <iostream>
#include <vector>
#include <string>
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "stopwatch.h"

using namespace std;

int main() {

    bool enterSort = false;
    int sortType;

    while (!enterSort) {
        cout << "Enter sort type (1 == Merge Sort, 2 == Quicksort): ";
        cin >> sortType;
        if (sortType == 1 || sortType == 2)
            enterSort = true;
    }

    bool enterDataType = false;
    string dataType;

    while (!enterDataType) {
        cout << "Enter data type (int or double): ";
        cin >> dataType;
        if (dataType == "int" || dataType == "double")
            enterDataType = true;
    }

    int numElements;
    cout << "Enter number of elements: ";
    cin >> numElements;

    cout << endl;

    srand(time(0));

    if (dataType == "int") {
        vector<int> list;

        for (int i = 0; i < numElements; i++) {
            int x = (rand() % 10) + 1;
            list.push_back(x);
            //cout << x << " ";
        }
        cout << endl;

        CStopWatch sortClock;

        if (sortType == 1) {
            mergeSort(list, 0, numElements-1);
        }
        else if (sortType == 2) {
            quickSort(list, 0, numElements-1);
        }

        cout << sortClock.GetElapsedSeconds() << endl;

        //for (int i = 0; i < numElements; i++)
            //cout << list.at(i) << " ";
    }
    else if (dataType == "double") {
        vector<double> list;

        for (int i = 0; i < numElements; i++) {
            double x = rand() / double(RAND_MAX);
            list.push_back(x);
            //cout << x << " ";
        }
        cout << endl;

        CStopWatch sortClock;

        if (sortType == 1) {
            mergeSort(list, 0, numElements-1);
        }
        else if (sortType == 2) {
            quickSort(list, 0, numElements-1);
        }

        cout << sortClock.GetElapsedSeconds() << endl;

        //for (int i = 0; i < numElements; i++)
            //cout << list.at(i) << " ";
    }
    cout << endl;

    return 0;
}