#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "mergeSort.cpp"
#include "quickSort.cpp"

using namespace std;

int main() {

    string input_file;
    cout << "Enter file name: ";
    cin >> input_file;

    ifstream ifs (input_file);

    if (!ifs.is_open())
        throw runtime_error("Unable to open file");

    int sortType;
    ifs >> sortType;

    int numElements;
    ifs >> numElements;

    vector<int> list;

    for (int i = 0; i < numElements; i++) {
        int num;
        ifs >> num;
        list.push_back(num);
    }

    if (sortType == 1) {
        mergeSort(list, 0, numElements-1);
        cout << "Merge Sort" << endl;
    }
    else if (sortType == 2) {
        quickSort(list, 0, numElements-1);
        cout << "Quicksort" << endl;
    }
    else
        throw runtime_error("Unable to determine which sort to use");

    for (int i = 0; i < numElements; i++)
        cout << list.at(i) << " ";

    cout << endl;

    return 0;
}