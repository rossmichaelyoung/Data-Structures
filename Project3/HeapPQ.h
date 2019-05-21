#ifndef PROJECT_3_HEAPPQ_H
#define PROJECT_3_HEAPPQ_H

template <class T>
class HeapPQ {

    T *arrayHeap;
    int arraySize;
    int n;

public:
    HeapPQ ();
    HeapPQ (T *dataArray, int num_elements);
    ~HeapPQ ();
    bool empty ();
    int size ();
    void insert (T data);
    T removeMin ();
    T minValue ();
    void sortBottomUp ();
    void sortTopDown (int index);
    void swap (int i, int v);
    int least (int i, int leftChild, int rightChild);
};

#endif //PROJECT_3_HEAPPQ_H