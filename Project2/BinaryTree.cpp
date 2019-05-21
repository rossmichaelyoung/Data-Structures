#include <stdexcept>
#include "BinaryTree.h"
using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    DeleteTree(root);
}

template <class T>
void BinaryTree<T>::DeleteTree(Node<T> *TreeNode) {
    if (TreeNode->left)
        DeleteTree(TreeNode->left);

    if (TreeNode->right)
        DeleteTree(TreeNode->right);

    delete TreeNode;
}

template <class T>
Node<T>* BinaryTree<T>::insert(T data, Node<T> *TreeNode) {
    if (TreeNode == nullptr) { // if the tree is empty, new node is the root
        root = new Node<T>(data);
        root->depth = 0;
        height = 0;
        return root;
    }

    else if (!TreeNode->left && data <= TreeNode->data) { // one possible base case
        Node<T> *NewNode = new Node<T>(data);
        TreeNode->left = NewNode;
        NewNode->parent = TreeNode;
        NewNode->depth = TreeNode->depth + 1;

        if (NewNode->depth > height)
            height = NewNode->depth;

        return NewNode;
    }

    else if (!TreeNode->right && data > TreeNode->data) { // the other possible base case
        Node<T> *NewNode = new Node<T>(data);
        TreeNode->right = NewNode;
        NewNode->parent = TreeNode;
        NewNode->depth = TreeNode->depth + 1;

        if (NewNode->depth > height)
            height = NewNode->depth;

        return NewNode;
    }

    else { // recursive step
        if (data <= TreeNode->data)
            return insert(data, TreeNode->left);

        else
            return insert(data, TreeNode->right);
    }
}

template <class T>
void BinaryTree<T>::PublicInsert(T data) {
    insert(data, root);
}

template <class T>
int BinaryTree<T>::TreeHeight() {
    if (root == nullptr)
        throw runtime_error ("Tree is empty");

    else
        return height;
}