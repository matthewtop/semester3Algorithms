#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    string color;
};


template <typename T>
class BRTree{
public:
    Node<T>* root;
    Node<T>* puste;

    void iniNull(Node<T> node, Node<T> parent){
        node->data;
        node->parent=parent;
        node->left= nullptr;
        node->right= nullptr;
        node->color="black";
    }

};