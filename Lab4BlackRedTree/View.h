#ifndef LAB4BLACKREDTREE_VIEW_H
#define LAB4BLACKREDTREE_VIEW_H

#include <iostream>

using namespace std;

class View {
public:

    static void mainMenu(){
        cout<<"============================================="<<endl;
        cout<<"|       1. Znajdz element                   |"<<endl;
        cout<<"|       2. Przejscie pre-order              |"<<endl;
        cout<<"|       3. Przejscie in-order               |"<<endl;
        cout<<"|       4. Wyczysc drzewo                   |"<<endl;
        cout<<"|       5. Wyznacz wysokosc                 |"<<endl;
        cout<<"|       6. Dodaj element                    |"<<endl;
        cout<<"|       7. Napisowa reprezentacja drzewa    |"<<endl;
        cout<<"|       8. Rotacja w lewo                   |"<<endl;
        cout<<"|       9. Rotacja w prawo                  |"<<endl;
        cout<<"|      10. Zakoncz prace programu           |"<<endl;
        cout<<"============================================="<<endl;
        cout<<"Twoj wybor: ";

    }

};


#endif //LAB4BLACKREDTREE_VIEW_H
