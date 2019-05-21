#include <iostream>
#include <ctime>
#include <cstdlib>
#include "DoublingArrayQueue.cpp"
#include "arrayQueue.cpp"
#include "LinkedListQueue.cpp"
#include "stopwatch.h"
using namespace std;

int main() {

    DoublingArrayQueue<int> *myArray = new DoublingArrayQueue<int>(5);

    //arrayQueue<int> *myArray = new arrayQueue<int>(5);

    //LinkedListQueue<int> *myArray = new LinkedListQueue<int>;

    srand(time(0));

    CStopWatch QueueClock;

    for (int i = 0; i <= 1000000000; i++) {
        myArray->enqueue((rand() % 1000));

        if ((i % 1000000) == 0)
            cout << QueueClock.GetElapsedSeconds() << endl;
    }

/*
    cout << myArray->empty() << endl;

    myArray->enqueue(5);
    myArray->enqueue(-12);
    myArray->enqueue(47);
    myArray->enqueue(-2);
    myArray->enqueue(-8);

    cout << myArray->size() << endl;

    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;

    myArray->enqueue(14);
    myArray->enqueue(22);
    myArray->enqueue(11);
    myArray->enqueue(77);

    cout << myArray->size() << endl;

    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;
    myArray->dequeue();

    cout << myArray->size() << endl;
    cout << myArray->empty() << endl;

    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;
    myArray->dequeue();
    cout << myArray->front() << endl;
    myArray->dequeue();

    cout << myArray->size() << endl;
    cout << myArray->empty() << endl;
*/
    delete myArray;

    return 0;
}