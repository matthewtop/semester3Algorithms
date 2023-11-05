//
// Created by mateu on 31.10.2023.
//

#ifndef LAB03_CLASSES_H
#define LAB03_CLASSES_H

#include <iostream>

using namespace std;

template <typename T>
class Tree{
public:
    Tree() {}

    T key;
    Tree *left;
    Tree *right;
    Tree *parent;


    Tree(T key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}
    //Tree()= default;
    ~Tree()= default;

    void dodaj(T key) {
        if (key < this->key) {
            if (left == nullptr) {
                left = new Tree(key);
                left->parent = this;
            } else {
                left->dodaj(key);
            }
        } else if (key > this->key) {
            if (right == nullptr) {
                right = new Tree(key);
                right->parent = this;
            } else {
                right->dodaj(key);
            }
        }
    }

    T getWartosc(){
        T wartosc;
        cout<<"Podaj wartosc do wprowadzenia: ";
        cin>>wartosc;
        return wartosc;
    }

    void showTree(){
        if (left != nullptr) {
            left->showTree();
        }
        cout << key << " ";
        if (right != nullptr) {
            right->showTree();
        }
    }



};


#endif //LAB03_CLASSES_H
