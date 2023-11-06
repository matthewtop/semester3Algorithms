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

    void preorder(){
            cout << key << " "; //korzen

            if (left != nullptr) {
                left->preorder();
            }
            if (right != nullptr) {
                right->preorder();
            }
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

    void clear(){
        if(checkIfTreeIsNotEmpty()== true) {
            if (left != nullptr) {
                left->clear();
                delete left;
                left = nullptr;
            }
            if (right != nullptr) {
                right->clear();
                delete right;
                right = nullptr;
            }
        } else{
            View::treeIsEmpty();
        }
    }

    Tree* znajdz(T key, int&index){
        if(this== nullptr){
            return nullptr;
        }

        if (this->key==key){
            index = this->index;
            return this;
        } else if (key< this->key){
            if (left!= nullptr){
                return left->znajdz(key, index);
            }
        } else{
            if (right != nullptr){
                return right->znajdz(key, index);
            }
        }
        return nullptr;
    }

    bool checkIfTreeIsNotEmpty(){
        if (left == nullptr && right == nullptr) {
            return false;
        } else{
            return true;
        }
    }

    int getHeight(){
        if(checkIfTreeIsNotEmpty()== true){
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
        else{
            return 1;
        }
    }

    void heightMessage(){
        cout<<"Wysokosc drzewa wynosi: "<<getHeight()<<endl;
    }

    bool usun(T key) {
        if (key < this->key) {
            if (left != nullptr) {
                if (left->key == key) {
                    return deleteLeft();
                } else {
                    return left->usun(key);
                }
            } else {
                View::wezelNieIstnieje();
                return false;
            }
        } else if (key > this->key) {
            if (right != nullptr) {
                if (right->key == key) {
                    return deleteRight();
                } else {
                    return right->usun(key);
                }
            } else {
                View::wezelNieIstnieje();
                return false;
            }
        } else {
            View::wezelNieIstnieje();
            return false;
        }
    }

    bool deleteLeft() {
        if (left != nullptr) {
            delete left;
            left = nullptr;
            View::sukces();
            return true;
        }
        return false;
    }

    bool deleteRight() {
        if (right != nullptr) {
            delete right;
            right = nullptr;
            View::sukces();
            return true;
        }
        return false;
    }

    void wyswietl() {
        if (right != nullptr) {
            right->wyswietl();
        }

        for (int i = 0; i < index; i++) {
            cout << "    ";
        }
        cout << key << endl;

        if (left != nullptr) {
            left->wyswietl();
        }
    }
    
    void zmienKorzen(T nowy){
        this->key=nowy;
    }

};


#endif //LAB03_CLASSES_H
