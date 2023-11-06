#include <iostream>
#include "View.h"
#include "classes.h"

using namespace std;

int main() {

    Tree<int> tree(10);

    int wybor;
    bool dzialanie = true;
    do {
        View::mainMenu();
        cin >> wybor;
        switch (wybor) {
            case 1:
                tree.dodaj(tree.getWartosc());
                break;
            case 2:
                tree.findNode(tree.getWartosc());
                ///
                break;
            case 3:
                ///
                break;
            case 4:
                tree.preorder();
                break;
            case 5:
                tree.inOrder();
                break;
            case 6:
                tree.clear();
                break;
            case 7:
                ///
                break;
            case 8:
                ///
                break;
            case 9:
                dzialanie= false;
                break;
            default:
                cout<<"Nieprawidlowy wybor sprobuj ponownie"<<endl;

        }
    } while (dzialanie);
}
