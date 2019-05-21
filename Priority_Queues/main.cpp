#include <iostream>
#include <fstream>
#include "UnsortedList.cpp"
#include "SortedList.cpp"
#include "Heap.cpp"
using namespace std;

int main() {

    string input_file;
    cin >> input_file;

    ifstream infs = ifstream(input_file);

    if (infs.is_open()) {
        int num;
        infs >> num;

        if (num == 0) {
            UnsortedList *PQ = nw
        }

        else if (num == 1) {

        }

        else if (num == 2) {

        }

        else
            throw runtime_error("Priority Queue unknown");
    }
    else
        throw runtime_error("File could not be opened");

    return 0;
}