#include <iostream>
#include <time.h>
#include <string>
#include "classes.h"

using namespace std;

int main() {

    auto* tablica = new DynamicArray<int>;
    int wybor;
    bool dzialanie=true;

    do {
        cout << "Wybierz opcje:" << endl;
        cout<<"1. Dodaj dane "<<endl;
        cout<<"2. Wyszukaj element po indeksie"<<endl;
        cout<<"3. Wyczysc tablice"<<endl;
        cout<<"4. Posortuj tablice babelkowo"<<endl;

        cin>>wybor;
        switch(wybor) {
            case 1: {
                clock_t t1 = clock();
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                tablica->add(3);

                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Nieprawidlowy wybor" << endl;
                break;
            }
        }
    }while(dzialanie);
}
