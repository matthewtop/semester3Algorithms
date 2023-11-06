#ifndef LAB03_CLASSES_H
#define LAB03_CLASSES_H

#include <iostream>

using namespace std;

template <typename T>
class Tree{
public:
    T key;
    Tree *left;
    Tree *right;
    Tree *parent;
    int index;

    Tree() : key(T()), left(nullptr), right(nullptr), parent(nullptr), index(-1) {}
    Tree(T key, int index) : key(key), left(nullptr), right(nullptr), parent(nullptr), index(index) {}
    ~Tree()= default;

    void dodaj(T key) {
        if (key < this->key) {
            if (left == nullptr) {
                left = new Tree(key, index+1);
                left->parent = this;
                left->index = index + 1;
            } else {
                left->dodaj(key);
            }
        } else if (key > this->key) {
            if (right == nullptr) {
                right = new Tree(key, index+1);
                right->parent = this;
                right->index = index + 1;
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
    }

    Tree* findNode(T key, int&foundIndex){
        if(this== nullptr){
            return nullptr;
        }

        if (this->key==key){
            foundIndex = this->index;
            return this;
        } else if (key< this->key){
            if (left!= nullptr){
                return left->findNode(key, foundIndex);
            }
        } else{
            if (right != nullptr){
                return right->findNode(key, foundIndex);
            }
        }
        return nullptr;
    }

    int getHeight(){
        int height = 0;
        if (this == nullptr) {
            cout << "Drzewo jest puste" << endl;
            return 0;
        }
        else{
            int leftHeight = 0;
            int rightHeight = 0;

            if (left != nullptr) {
                leftHeight = left->getHeight();
            }

            if (right != nullptr) {
                rightHeight = right->getHeight();
            }

            return max(leftHeight, rightHeight) + 1;
        }
    }

    void heightMessage(){
        cout<<"Wysokosc drzewa wynosi: "<<getHeight()<<endl;
    }

    bool usun(T key){
        if (key<this->key){
            if(left!= nullptr){
                if (left->key==key){
                    delete left;
                    left= nullptr;
                    cout<<"Udalo sie usunac wezel"<<endl;
                    return true;
                } else{
                    return left->usun(key);
                }
            }
        } else if (key > this->key){
            if(right!= nullptr){
                if (right->key==key){
                    delete right;
                    right= nullptr;
                    cout<<"Udalo sie usunac wezel"<<endl;
                    return true;
                }else{
                    return right->usun(key);
                }
            }
        }
        cout<<"Wezel nie istnieje"<<endl;
        return false;
    }

    void wyswietl(int poziom = 0) {
        if (this == nullptr) {
            cout<<"Drzewo jest puste"<<endl;
            return;
        }

        if (right != nullptr) {
            right->wyswietl(poziom + 1);
        }

        for (int i = 0; i < poziom; i++) {
            cout << "    ";
        }
        cout << key << endl;

        if (left != nullptr) {
            left->wyswietl(poziom + 1);
        }
    }
    void wyswietlLewo(){

    }

    void zmienKorzen(T nowy){
        this->key=nowy;
    }





};


#endif //LAB03_CLASSES_H
