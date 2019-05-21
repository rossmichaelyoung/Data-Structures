#include <iostream>
#include <vector>

using namespace std;

template <class T>
void swap(vector<T>& arr, int firstIndex, int secondIndex) {
    T temp = arr.at(firstIndex);
    arr.at(firstIndex) = arr.at(secondIndex);
    arr.at(secondIndex) = temp;
}

template <class T>
int partition(vector<T>& arr, int low, int high) {
    srand(time(0));

    int p = (rand() % (high - low)) + low;

    swap(arr, p, low);
    T pivot = arr.at(low);
    int left = low;

    for (int i = low+1; i <= high; i++) {
        if (arr.at(i) < pivot) {
            left++;
            swap(arr, i, left);
        }
    }
    swap(arr, low, left);
    return left;
}

template <class T>
void quickSort(vector<T>& arr, int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot-1);
        quickSort(arr, pivot+1, last);
    }
}