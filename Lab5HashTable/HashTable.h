#ifndef LAB5HASHTABLE_HASHTABLE_H
#define LAB5HASHTABLE_HASHTABLE_H

#include <iostream>
#include <list>
#include <sstream>

using namespace std;

template <typename T>
class HashTable {
public:

    int size;
    int maxSize;
    T* hashtable;

    HashTable() {
        size = 0;
        maxSize = 2;
        hashtable = new T[maxSize];
    }

    ~HashTable() {delete[] hashtable;}

    int hash(T element) {
        return element % maxSize;
    }

    void rehash() {
        maxSize *= 2;
        T* temp = new T[maxSize];

        for (int i = 0; i < size; i++) {
            int index = hash(hashtable[i]);
            temp[index] = hashtable[i];
        }

        delete[] hashtable;
        hashtable = temp;
    }

    void insert(T element) {
        if (size >= maxSize) {
            rehash();
        }

        for (int i = 0; i < size; ++i) {
            if (hashtable[i] == element) {
                cout << "Element o kluczu " << element << " juz istnieje." << endl;
                return;
            }
        }
        hashtable[size++] = element;
    }


    void addMaxSize(){
        maxSize *=2;
        T *temp = new T[maxSize];

        for(int i=0; i<size;i++){
            temp[i] = hashtable[i];
        }
        delete[] hashtable;
        hashtable=temp;
    }

    void checkSize(){
        if(size >= maxSize)
            addMaxSize();
    }

    void checkIfArrayIsNotEmpty(){
        if(size==0){
            cout<<"Tablica jest pusta"<<endl;
            return;
        }
    }

    void insert() {
        T element;
        cout << "Podaj element: " << endl;
        cin >> element;
        for (int i = 0; i < size; ++i) {
            if (hashtable[i] == element) {
                cout << "Element o kluczu " << element << " już istnieje. Nie można wstawić duplikatu." << endl;
                return;
            }
        }
        clock_t t1 = clock();
        checkSize();
        hashtable[size++] = element;
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds * 1000;
        cout << miliseconds << " ms" << endl;
    }

    void insertRandomValues() {
        int numOfElem;
        cout << "Podaj ilosc elementow do wygenerowania i wprowadzenia: " << endl;
        cin >> numOfElem;

        if (numOfElem < 0) {
            cout << "Niepoprawna wartosc" << endl;
            return;
        }

        clock_t t1 = clock();
        srand(static_cast<unsigned>(time(nullptr)));

        for (int i = 0; i < numOfElem; i++) {
            T randomValue = rand();
            insert(randomValue);
        }

        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double)CLOCKS_PER_SEC;
        double milliseconds = seconds * 1000;
        cout << milliseconds << " ms" << endl;
    }

    T& search(int index) {
        checkIfArrayIsNotEmpty();
        if (index >= size)
            cout << "Niepoprawny index" << endl;
        cout << index << ": " << hashtable[index] << " -> " << hash(hashtable[index]) << "; " << endl;
        return hashtable[index];
    }


    void clearTable(){
        checkIfArrayIsNotEmpty();
        clock_t t1 = clock();
        delete[] hashtable;
        size=0;
        maxSize=50;
        hashtable = new T[maxSize];
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    string toString() {
        checkIfArrayIsNotEmpty();
        stringstream result;

        clock_t t1 = clock();
        for (int i = 0; i < size; i++) {
            result << i << ": " << hashtable[i] << " -> " << hash(hashtable[i]) << "; \n";
        }
        clock_t t2 = clock();

        double seconds = (t2 - t1) / (double)CLOCKS_PER_SEC;
        double miliseconds = seconds * 1000;
        cout << miliseconds << " ms" << endl;
        return result.str();
    }

    void usun(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                hashtable[i] = hashtable[i + 1];
            }
            size--;
        } else {
            cout << "Zly index" << endl;
        }
    }

    int liczBezZer() {
        int nonZeroCount = 0;
        for (int i = 0; i < size; ++i) {
            if (hashtable[i] != 0) {
                nonZeroCount++;
            }
        }
        return nonZeroCount;
    }

    void stats(){
        int niezerowe = liczBezZer();
        cout<<"Obecny rozmiar: "<<size<<endl;
        cout<<"Maxymalny rozmiar: "<<maxSize<<endl;
        cout << "Liczba niezerowych wartosci: " << niezerowe << endl;
        cout<<"Liczba nullowych kubelkow: "<< maxSize-niezerowe<<endl;
    }
};

#endif //LAB5HASHTABLE_HASHTABLE_H