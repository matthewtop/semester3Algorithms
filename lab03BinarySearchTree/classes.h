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
        cout<<"Podaj wartosc: ";
        cin>>wartosc;
        return wartosc;
    }

    void inOrder(){
        if (left != nullptr) {
            left->inOrder();
        }
        cout << key << " ";
        if (right != nullptr) {
            right->inOrder();
        }
    }

    void preorder(){
        cout<<key<<" "; //korzen

        if(left != nullptr){
            left->preorder();
        }
        if (right!= nullptr){
            right->preorder();
        }
    }

    void clear(){
        if (left != nullptr){
            left->clear();
            delete left;
            left= nullptr;
        }
        if(right!= nullptr){
            right->clear();
            delete right;
            right= nullptr;
        }
        //todo: zeby usuwalo wszystko, korzen zostaje
    }

    Tree* findNode(T key){
        if(this== nullptr){
            return nullptr;
        }

        if (this->key==key){
            return this;
        } else if (key< this->key){
            if (left!= nullptr){
                return left->findNode(key);
            }
        } else{
            if (right != nullptr){
                return right->findNode(key);
            }
        }
        return nullptr;
    }





};


#endif //LAB03_CLASSES_H
