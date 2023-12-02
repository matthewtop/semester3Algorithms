#ifndef LAB5HASHTABLE_VIEW_H
#define LAB5HASHTABLE_VIEW_H
#include <iostream>
using namespace std;

class View {
public:
    static void mainMenu(){
        cout<<"========================================="<<endl;
        cout<<"|       0. Dodaj losowe elementy         |"<<endl;
        cout<<"|       1. Dodaj element                 |"<<endl;
        cout<<"|       2. Wyszukaj element              |"<<endl;
        cout<<"|       3. Usun element                  |"<<endl;
        cout<<"|       4. Wyczysc tablice               |"<<endl;
        cout<<"|       5. Wyswietl tablice              |"<<endl;
        cout<<"|       6. Rozszerz i przemieszaj tablice|"<<endl;
        cout<<"|       7. Wyswietl statystyki           |"<<endl;
        cout<<"|       8. Zakoncz dzialanie             |"<<endl;
        cout<<"=========================================="<<endl;
        cout<<"Twoj wybor: ";
    }

};


#endif //LAB5HASHTABLE_VIEW_H
