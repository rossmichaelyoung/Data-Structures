#include <iostream>
#include <vector>

using namespace std;

template <class T>
void merge(vector<T>& arr, int first, int mid, int last) {
    if (arr.at(mid) <= arr.at(mid+1))
        return;

    vector<T> L, R;

    for (int i = first; i <= mid; i++)
        L.push_back(arr.at(i));

    for (int i = mid+1; i <= last; i++)
        R.push_back(arr.at(i));

    int left = mid - first + 1;
    int right = last - mid;

    int i = 0;
    int j = 0;
    int k = first;

    while (i < left && j < right) {
        if (L.at(i) <= R.at(j)) {
            arr.at(k) = L.at(i);
            i++;
        }
        else {
            arr.at(k) = R.at(j);
            j++;
        }
        k++;
    }

    while (i < left) {
        arr.at(k) = L.at(i);
        i++;
        k++;
    }

    while (j < right) {
        arr.at(k) = R.at(j);
        j++;
        k++;
    }
}

template <class T>
void mergeSort(vector<T>& arr, int first, int last) {
    if (first < last) {
        int mid = (last + first) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }
}