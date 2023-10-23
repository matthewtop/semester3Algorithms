#ifndef LAB01_CLASSES_H
#define LAB01_CLASSES_H
#include <string>
#include <utility>

using namespace std;
class Data{
public:
    string brand;
    string model;
    int power{};

    Data()= default;

    Data(const string& brand, const string& model, int power)
            : brand(brand), model(model), power(power) {}


    ~Data()=default;


};

class Node{
public:
    Node* prev;
    Node* next;
    Data data;

    Node(){
        prev= nullptr;
        next= nullptr;
    }

    Node(const Data& carData){
        prev= nullptr;
        next= nullptr;
        data=carData;
    }

    ~Node()= default;

};

class List{
public:
    Node* head;
    Node* tail;
    int size;

    List(){
        tail= nullptr;
        head= nullptr;
        size=0;
    }
    ~List()= default;


    void insertAtTail(const Data& carData){
        if (head==nullptr){
            insertAtHead(carData);
            return;
        }

        Node* node= new Node(carData);
        Node* temp = head;
        while (temp->next!= nullptr){
            temp=temp->next;
        }

        temp-> next=node;
        node-> prev=temp;
        tail=node;
        size++;

    }

    void insertAtHead(const Data& carData){
        Node* node= new Node(carData);
        node->next=head;
        if (head!= nullptr){
            head->prev=node;
        }
        head=node;
        if(tail!= nullptr){
            tail=node;
        }
        size++;
    }

    void printList() {
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            cout << index << ". Brand: " << temp->data.brand << ", Model: " << temp->data.model << ", Power: " << temp->data.power << endl;
            temp = temp->next;
            index++;
        }
    }


    void deleteFirstElement() {
        if (head != nullptr) {
            Node* nodeToDelete = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete nodeToDelete;
            size--;
        }
    }

    void deleteLastElement() {
        if (tail != nullptr) {
            Node* nodeToDelete = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete nodeToDelete;
            size--;
        }
    }

    void clearList() {
        while (head != nullptr) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
        tail = nullptr;
        size = 0;
    }

    Data getDataFromIndex(int index) {
        if (index < 1 || index > size) {
            cerr << "Indeks poza zakresem." << endl;
            // Zwracamy pusty obiekt Data, aby wskazać błąd
            return Data();
        }

        Node* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }

        // Zwracamy dane znalezione pod podanym indeksem
        return temp->data;
    }


};

#endif //LAB01_CLASSES_H