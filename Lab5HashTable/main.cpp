#include <iostream>
#include <time.h>
#include <string>
#include "View.h"
#include "HashTable.h"
using namespace std;

int main() {
    HashTable<int> hashTable{};
    int wybor;
    bool dzialanie=true;

    do {
        View::mainMenu();
        cin>>wybor;
        switch(wybor) {
            case 0:{
                hashTable.insertRandomValues();
                break;
            }
            case 1: {
                hashTable.insert();
                break;
            }
            case 2:{
                int index;
                cout<<"Podaj index: ";
                cin>>index;
                clock_t t1 = clock();
                int wynik = hashTable.search(index);
                cout<<wynik<<endl;
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 3: {
                int index;
                cout<<"Podaj index: ";
                cin>>index;
                hashTable.usun(index);
                break;
            }
            case 4: {
                hashTable.clearTable();
                break;
            }
            case 5: {
                cout<<hashTable.toString()<<endl;
                cout<<endl;
                hashTable.stats();
                break;
            }
            case 6:{
                hashTable.rehash();
                break;
            }
            case 7: {
                hashTable.stats();
                break;
            }
            case 8:
                dzialanie=false;
                break;
            default: {
                cout << "Nieprawidlowy wybor" << endl;
                break;
            }
        }
    }while(dzialanie);
}