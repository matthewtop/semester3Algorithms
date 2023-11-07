#include <iostream>
#include "View.h"
#include "classes.h"

int main() {
    int wybor;
    bool dzialanie;
    do{
        View::mainMenu();
        cin>>wybor;
        switch (wybor) {
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                break;
            }
            case 8:{
                break;
            }
            case 9:{
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
