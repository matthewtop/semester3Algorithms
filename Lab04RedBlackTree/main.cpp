#include <iostream>
#include "View.h"
#include "Classes.h"

using namespace std;

int main(){
    RBT * rbt = new RBT();
    int wybor;
    bool dzialanie= true;
    do{
        View::mainMenu();
        cin>>wybor;
        switch (wybor) {
            case 0:{
                rbt->insertRandomValues();
                break;
            }
            case 1:{
                clock_t t1 = clock();
                int wartosc;
                View::getIlosc();
                cin>>wartosc;
                rbt->search(wartosc);
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 2:{
                clock_t t1 = clock();
                rbt->preOrder(rbt->root);
                cout<<endl;
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 3:{
                clock_t t1 = clock();
                rbt->inOrder(rbt->root);
                cout<<endl;
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 4:{
                rbt->clearTree();
                break;
            }
            case 5:{
                cout<<rbt->getHeight()<<endl;
                break;
            }
            case 6:{
                int wartosc;
                View::getWartosc();
                cin>>wartosc;
                clock_t t1 = clock();
                rbt->insert(wartosc);
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 7:{
                clock_t t1 = clock();
                rbt->display();
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 8:{
                clock_t t1 = clock();
                rbt->leftRotate(rbt->root);
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 9:{
                clock_t t1 = clock();
                rbt->rightRotate(rbt->root);
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 10:{
                dzialanie=false;
                break;
            }
            default:{
                View::nieprawidlowyWyborError();
                break;
            }
        }
    }while(dzialanie);
}
