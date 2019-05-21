#include <iostream>
#include "PriorityQueue.cpp"

int main() {

    PriorityQueue<string> *priorityQueue = new PriorityQueue<string>(10);

    cout << priorityQueue->empty() << endl;
    priorityQueue->insert(10, "Bob");
    priorityQueue->insert(10, "John");
    priorityQueue->insert(1, "Jim");
    priorityQueue->insert(4, "Frank");
    priorityQueue->Print();
    cout << endl;
    cout << priorityQueue->min() << endl;
    priorityQueue->removeMin();
    priorityQueue->Print();
    cout << endl;
    priorityQueue->removeMin();
    priorityQueue->insert(0, "Ross");
    priorityQueue->Print();

    return 0;
}