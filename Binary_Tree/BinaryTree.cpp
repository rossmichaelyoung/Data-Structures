#include <iostream>
#include <stack>
#include <queue>
#include "BinaryTree.h"
#include "Node.h"
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
void BinaryTree<T>::DeleteTree(Node<T> *leaf) {
    if (leaf != nullptr) {
        DeleteTree(leaf->left);
        DeleteTree(leaf->right);
        delete leaf;
    }
}

template <class T>
void BinaryTree<T>::insert(T data, Node<T> *leaf) {
    if (data < leaf->data) {
        if (leaf->left != nullptr) {
            insert(data, leaf->left);
        } else {
            leaf->left = new Node<T>;
            leaf->left->data = data;
            leaf->left->parent = leaf;
        }
    } else if (data >= leaf->data) {
        if (leaf->right != nullptr) {
            insert(data, leaf->right);
        } else {
            leaf->right = new Node<T>;
            leaf->right->data = data;
            leaf->right->parent = leaf;
        }
    }
}

template <class T>
void BinaryTree<T>::insert(T data) {
    if (root == nullptr) {
        Node<T> *current = new Node<T>;
        current->data = data;
        root = current;
    }

    else
        insert(data, root);
}

template <class T>
void BinaryTree<T>::PreOrder() {
    if (root == nullptr)
        throw runtime_error("Binary Tree is empty");

    stack<Node<T> *> NodeStack;
    Node<T> *leaf = this->root;
    NodeStack.push(leaf);

    while (!NodeStack.empty()) {
        leaf = NodeStack.top();
        cout << leaf->data << "–";
        NodeStack.pop();

        if (leaf->right) {
            NodeStack.push(leaf->right);
        }

        if (leaf->left) {
            NodeStack.push(leaf->left);
        }
    }
}

template <class T>
void BinaryTree<T>::InOrder() {
    if (root == nullptr)
        throw runtime_error("Binary Tree is empty");

    stack<Node<T> *> NodeStack;
    Node<T> *current = this->root;

    while (current || !NodeStack.empty()) {

        while (current) {
            NodeStack.push(current);
            current = current->left;
        }

        current = NodeStack.top();
        NodeStack.pop();

        cout << current->data << "–";

        current = current->right;
    }
}

template <class T>
void BinaryTree<T>::PostOrder() {
    if (root == nullptr)
        throw runtime_error("Binary Tree is empty");

    Node<T> *current = this->root;
    stack<Node<T> *> NodeStack;

    do {
        while (current != nullptr) {
            if (current->right) {
                NodeStack.push(current->right);
            }

            NodeStack.push(current);
            current = current->left;
        }

        current = NodeStack.top();
        NodeStack.pop();

        if (current->right && NodeStack.top() == current->right) {
            NodeStack.pop();
            NodeStack.push(current);
            current = current->right;
        }

        else {
            cout << current->data << "–";
            cout << "here" << endl;
            current = nullptr;
        }

    } while (!NodeStack.empty());
}

template <class T>
void BinaryTree<T>::LevelOrder() {
    if (root == nullptr)
        throw runtime_error("Binary Tree is empty");

    queue<Node<T> *> NodeQueue;
    Node<T> *current = this->root;
    NodeQueue.push(current);

    while (!NodeQueue.empty()) {
        current = NodeQueue.front();
        cout << current->data << "–";
        NodeQueue.pop();

        if (current->left) {
            NodeQueue.push(current->left);
        }

        if (current->right) {
            NodeQueue.push(current->right);
        }
    }
}