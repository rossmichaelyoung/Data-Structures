#include <iostream>
#include <ctime>
#include "BinaryTree.cpp"
using namespace std;

int main() {

    srand(time(0));

    for (int i = 0; i < 50; i++) {
        //BinaryTree<int> *Tree = new BinaryTree<int>;
        BinaryTree<double> *Tree = new BinaryTree<double>;
        for (int j = 0; j < 300; j++) {
            //int x = rand() % 11;
            double x = rand() / double(RAND_MAX);
            Tree->PublicInsert(x);
        }
        cout << Tree->TreeHeight() << endl;
        delete Tree;
    }

    return 0;
}