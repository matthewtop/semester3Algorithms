#ifndef LAB02_DYNAMICARRAY_H
#define LAB02_DYNAMICARRAY_H
#include <string>

using namespace std;

template<typename T>
class DynamicArray{
public:
    int size;
    int maxSize;
    T* dynamicArray;

    DynamicArray(){
        size=0;
        maxSize=50;
        dynamicArray= new T[maxSize];
    }

    void addMaxSize(){
        maxSize *=2;
        T *temp = new T[maxSize];

        for(int i=0; i<size;i++){
            temp[i] = dynamicArray[i];
        }

        delete [] dynamicArray;
        dynamicArray=temp;
    }

    void insert(T element){
        if(size >= maxSize)
            addMaxSize();
        dynamicArray[size++]=element;
    }

    void insert(){
        T element;
        cout<<"Podaj element: "<<endl;
        cin>>element;
        clock_t t1 = clock();
        if(size >= maxSize)
            addMaxSize();
        dynamicArray[size++]=element;
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    void insertRandomValues(DynamicArray<T> &dynamicArray){
        int numOfElem;
        cout<<"Podaj ilosc elementow do wygenerowania i wprowadzenia: "<<endl;
        //todo OGARNAC SEED
        cin>>numOfElem;
        clock_t t1 = clock();
        srand(time(nullptr));
        for (int i = 0; i<numOfElem-1 ; i++) {
            T randomValue = rand();
            dynamicArray.insert(randomValue);
        }
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    T& search(int index){
        if(index<0||index>=size)
            cout<<"Niepoprawny index";
        return dynamicArray[index];
    }

    void replace(){
        int index;
        T value;
        cout << "Podaj index do podmiany: ";
        cin >> index;
        cout << "Wprowadz wartosc: ";
        cin >> value;
        clock_t t1 = clock();
        if (index<0 || index >= size){
            cout<<"Zly index"<<endl;
            return;
        }
        dynamicArray[index]=value;
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    void clearArray(){
        clock_t t1 = clock();
        delete[] dynamicArray;
        size=0;
        maxSize=50;
        dynamicArray = new T[maxSize];
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    void printArray(){
        for (int i = 0; i < size; i++) {
            cout<<dynamicArray[i]<<" ";
        }
    }

    string toString() {
        string result;
        for (int i = 0; i < size; i++) {
            result += to_string(dynamicArray[i]) + " ";
        }
        return result;
    }

    void bubblesort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (dynamicArray[j] > dynamicArray[j + 1]) {
                    T temp = dynamicArray[j];
                    dynamicArray[j] = dynamicArray[j + 1];
                    dynamicArray[j + 1] = temp;
                    //swap = true;
                }
            }
        }
    }
};
#endif //LAB02_DYNAMICARRAY_H
