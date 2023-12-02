#include <iostream>
#include "View.h"
#include "classes.h"

int main() {

    RBTree<int> drzewo;

    int wybor;
    bool dzialanie= true;
    do{
        View::mainMenu();
        cin>>wybor;
        switch (wybor) {
            case 1:{
                clock_t t1 = clock();
                //todo:
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 2:{
                clock_t t1 = clock();
                //TODO:
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 3:{
                clock_t t1 = clock();
                drzewo.inOrder(drzewo.root);
                cout<<endl;
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 4:{
                clock_t t1 = clock();
                drzewo.clearTree(drzewo.root);
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 5:{
                View::heightMess(drzewo.getHeight(drzewo.root));
                break;
            }
            case 6:{
                drzewo.dodaj(drzewo.getValue());
                break;
            }
            case 7:{
                clock_t t1 = clock();
                //TODO:
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 8:{
                clock_t t1 = clock();
                //TODO:
                clock_t t2 = clock();
                double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
                double miliseconds = seconds*1000;
                cout << miliseconds << " ms" << endl;
                break;
            }
            case 9:{
                clock_t t1 = clock();
                //TODO:
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
                cout<<"Nieprawidlowy wybor sprobuj ponownie"<<endl;
                break;
            }

        }

    }while(dzialanie);
}
