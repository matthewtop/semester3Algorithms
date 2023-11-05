#include <iostream>
#include "View.h"
#include "classes.h"

using namespace std;

int main() {

    Tree<int> tree(10);  // Inicjalizacja drzewa z korzeniem o kluczu 50

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
                ///
                break;

        }
    } while (dzialanie);
}
