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

    void insertRandomValues(DynamicArray<T> &dynamicArray, int numOfElem){
        srand(time(nullptr));
        for (int i = 0; i<numOfElem ; i++) {
            T randomValue = rand();
            dynamicArray.insert(randomValue);
        }
    }

    T& search(int index){
        if(index<0||index>=size)
            throw "Out of bounds exception";
        return dynamicArray[index];
    }

    void replace(DynamicArray<T> &dynamicArray){
        int index;
        T value;
        cout << "Podaj index do podmiany: ";
        cin >> index;
        cout << endl;
        cout << "Wprowadz wartosc: ";
        cin >> value;
        if (index<0 || index >= dynamicArray.size){
            cout<<"Zly index"<<endl;
            return;
        }
        dynamicArray[index]=value;
    }

    void clearArray(){
        delete[] dynamicArray;
        size=0;
        maxSize=50;
        dynamicArray = new T[maxSize];
    }

    void printArray(DynamicArray<T> &dynamicArray){
        for (int i = 0; i < dynamicArray.size; i++) {
            cout<<dynamicArray.dynamicArray[i]<<" ";
        }
        cout<<endl;
    }


    void bubblesort(DynamicArray<T>& dynamicArray) {
        bool swap;
        clock_t t1 = clock();
        for (int i = 0; i < dynamicArray.size - 1; i++) {
            swap = false;
            for (int j = 0; j < dynamicArray.size - i - 1; j++) {
                if (dynamicArray[j] > dynamicArray[j + 1]) {
                    T temp = dynamicArray[j];
                    dynamicArray[j] = dynamicArray[j + 1];
                    dynamicArray[j + 1] = temp;
                    swap = true;
                }
            }
            if (swap==false) {
                break;
            }
        }
        clock_t t2 = clock();
        double seconds = (t2 - t1) / (double) CLOCKS_PER_SEC;
        double miliseconds = seconds*1000;
        cout << miliseconds << " ms" << endl;
    }

    T& operator[] (const int index){
        if (index<0 || index >= size){
            throw "zly index";
        }
        return dynamicArray[index];
    }

    string toString(DynamicArray<T> &dynamicArray){
        string result;
        for(int i=0; i<dynamicArray.maxSize; i++){
            result+= to_string(dynamicArray[i]);
            if (i<size -1){
                result += ", ";
            }
        }
        result += "]";
        return  result;
    }
};
#endif //LAB02_DYNAMICARRAY_H
