#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    string color;
};

template <typename T>
class RBTree {
public:
    Node<T>* root;
    int size;

    RBTree() : root(nullptr), size(0){}

    ~RBTree() { clearTree(root); }

    Node<T>* iniNull(Node<T>* parent = nullptr) {
        auto* node = new Node<T>();
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = "black";
        return node;
    }

    void dodaj(T data) {
        clock_t t1 = clock();
        auto* newNode = new Node<T>();
        newNode->data = data;
        newNode->left = iniNull(newNode);
        newNode->right = iniNull(newNode);
        newNode->color = "red";

        if (root == nullptr) {
            root = newNode;
            root->color = "black";
        } else {
            dodajHelper(root, newNode);
            naprawDodaj(newNode);
        }
        size++;

        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    T getValue(){
        T value;
        cout<< "Podaj wartosc: ";
        cin>> value;
        return value;
    }

    void dodajHelper(Node<T> *newNode, Node<int> *pNode) {
        if (newNode->data < root->data) {
            if (root->left == nullptr || root->left->data == T()) {
                root->left = newNode;
                newNode->parent = root;
            } else {
                dodajHelper(root->left, newNode);
            }
        } else if (newNode->data > root->data) {
            if (root->right == nullptr || root->right->data == T()) {
                root->right = newNode;
                newNode->parent = root;
            } else {
                dodajHelper(root->right, newNode);
            }
        }
    }

    void naprawDodaj(Node<T>* newNode) {
        while (newNode->parent != nullptr && newNode->parent->color == "red") {
            Node<T>* uncle = nullptr;

            if (newNode->parent == newNode->parent->parent->left) {
                uncle = newNode->parent->parent->right;

                if (uncle->color == "red") {
                    newNode->parent->color = "black";
                    uncle->color = "black";
                    newNode->parent->parent->color = "red";
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        rotacjaLewo(newNode);
                    }

                    newNode->parent->color = "black";
                    newNode->parent->parent->color = "red";
                    rotacjaPrawo(newNode->parent->parent);
                }
            } else {
                uncle = newNode->parent->parent->left;

                if (uncle->color == "red") {
                    newNode->parent->color = "black";
                    uncle->color = "black";
                    newNode->parent->parent->color = "red";
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rotacjaPrawo(newNode);
                    }

                    newNode->parent->color = "black";
                    newNode->parent->parent->color = "red";
                    rotacjaLewo(newNode->parent->parent);
                }
            }
        }

        root->color = "black";
    }

    void rotacjaLewo(Node<T>* x) {
        Node<T>* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotacjaPrawo(Node<T>* x) {
        Node<T>* y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->right = x;
        x->parent = y;
    }

    void clearTree(Node<T>* node) {
        if (node != nullptr && node->data != T()) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }

    int getHeight(Node<T>* node) {
        if (node == nullptr || node->data == T()) {
            return 0;
        } else {
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);

            return 1 + max(leftHeight, rightHeight);
        }
    }

    void inOrder(Node<T>* root){
        if(root== nullptr){
            return;
        }

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

};