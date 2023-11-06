#include <iostream>
#include "View.h"
#include "classes.h"

using namespace std;

int main() {

    Tree<int> tree(10,0);

    int wybor;
    bool dzialanie = true;
    do {
        View::mainMenu();
        cin >> wybor;
        switch (wybor) {
            case 1: {
                tree.dodaj(tree.getWartosc());
                break;
            }
            case 2: {
                int foundIndex = -1;
                Tree<int> *foundNode = tree.findNode(tree.getWartosc(), foundIndex);
                if (foundNode) {
                    cout << "Znaleziono wezel, jego index to: " << foundIndex << endl;
                } else {
                    cout << "nie zostal znaleziony." << endl;
                }
                break;
            }
            case 3: {
                tree.usun(tree.getWartosc());
                break;
            }
            case 4: {
                tree.preorder();
                break;
            }
            case 5: {
                tree.inOrder();
                break;
            }
            case 6: {
                tree.clear();
                break;
            }
            case 7: {
                tree.heightMessage();
                break;
            }
            case 8: {
                tree.wyswietl();
                break;
            }
            case 9:{
                tree.zmienKorzen(tree.getWartosc());
                break;
            }
            case 10: {
                dzialanie = false;
                break;
            }
            default: {
                cout << "Nieprawidlowy wybor sprobuj ponownie" << endl;
            }
        }
    } while (dzialanie);
}
