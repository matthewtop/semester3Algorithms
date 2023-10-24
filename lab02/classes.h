#ifndef LAB02_CLASSES_H
#define LAB02_CLASSES_H

using namespace std;

template<typename T>
class DynamicArray{
public:
    T size;
    T maxSize;
    T wspolzczynnik_rozszerzania;

    DynamicArray()= default;

    DynamicArray(T rozmiar){
        this->size=rozmiar;
    }

    ~DynamicArray()= default;

    void add(T newData);
    void search(int index);
    void clearArray();
    void bubbleSort();
};

#endif //LAB02_CLASSES_H
