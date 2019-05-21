#include <iostream>
#include "BinaryTree.cpp"
using namespace std;

int main() {
    
    BinaryTree<int> *TestTree = new BinaryTree<int>;

    TestTree->insert(10);
    TestTree->insert(5);
    TestTree->insert(12);
    TestTree->insert(2);
    TestTree->insert(8);
    TestTree->insert(6);
    TestTree->insert(9);
    TestTree->insert(11);
    TestTree->insert(15);
    TestTree->insert(14);

    TestTree->PreOrder();
    cout << endl;
    TestTree->InOrder();
    cout << endl;
    TestTree->PostOrder();
    cout << endl;
    TestTree->LevelOrder();

    delete TestTree;
    return 0;
}