#include <iostream>

using namespace std;

enum Color {
    RED, BLACK
};

class TreeNode {
public:

    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
    Color color;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        color = RED;
    }

    ~TreeNode(){
        delete left;
        delete right;
        delete parent;
    }
};

class BST {
public:
    TreeNode * root;

    BST() {
        root = nullptr;
    }

    ~BST() {
        delete root;
    }

    virtual TreeNode * insert(int data) {

        auto * newNode = new TreeNode(data);

        if (root == nullptr) {
            root = newNode;
            root->color=BLACK;
            return root;
        }

        TreeNode * current = root;
        TreeNode * parent = nullptr;

        while(current != nullptr){

            parent = current;

            if(newNode->data < current->data){
                current = current->left;
            } else if (newNode->data > current->data) {
                current = current->right;
            }
            else {
                delete newNode;
                //return newNode;
                return nullptr;
            }

        }

        newNode->parent = parent;

        if(newNode->data < parent->data){
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        return newNode;
    }

    void print(const string &prefix, TreeNode * parent, bool isLeft, bool isRoot) {
        if (parent == nullptr)
            return;

        if (isRoot) {
            cout << "─────";
        } else {
            cout << prefix <<
                 (isLeft ? "L-------" : "R------");
        }

        cout << " " << parent->color << " - " <<  parent -> data << endl;

        print(prefix + (isLeft ? " │   " : "    "),
              parent -> left, true, false);
        print(prefix + (isLeft ? " │   " : "    "),
              parent -> right, false, false);
    }

    void display() {
        print("", root, false, true);;
    }


    int height(TreeNode *node) {
        if (node == nullptr)
            return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int getHeight() {
        return height(root);
    }
};

class RBT : public BST {
public:

    RBT(){}

    ~RBT(){}

    TreeNode * insert(int data) override {
        TreeNode * newNode = BST::insert(data);
        if (newNode != nullptr) {
            dodajFix(newNode);
        }
        return newNode;
    }

    void dodajFix(TreeNode *z){
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                TreeNode *y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                TreeNode *y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void leftRotate(TreeNode * x){

        TreeNode * y = x->right;

        x->right = y->left;

        if(y->left != nullptr){
            y->left->parent = x;
        }

        y->parent = x->parent;

        if(x->parent == nullptr){
            BST::root = y;
        } else if(x == x->parent->left){
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(TreeNode * x){

        TreeNode * y = x->left;

        x->left = y->right;

        if(y->right != nullptr){
            y->right->parent = x;
        }

        y->parent = x->parent;

        if(x->parent == nullptr){
            BST::root = y;
        } else if(x == x->parent->right){
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

};


int main(int argc, char const *argv[])
{
    RBT * rbt = new RBT();
    rbt->insert(3);
    rbt->insert(2);
    rbt->insert(1);
    rbt->insert(100);
    cout<<rbt->getHeight()<<endl;

    rbt->display();


    return 0;
}