#include "Node.h"
#include"header.h"
#include "extern.h"


template <typename T>
class list {
    Node<T>* head;

public:
    list() { 
        logs << "kontruktor klasy list" << endl;
        this->head = NULL; 
    }
    ~list()
    {
        logs << "uruchomiono destruktor listy" << endl;

        Node<T>* current = head;
        while (current != 0) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = 0;
    }


    void push(T n);
    void printList();
    int size();
    T& operator[](int) const;
};


template <typename T>
void list<T>::push(T content)
{
    logs << "uruchomiono funkcje LIST::PUSH" << endl;
    Node<T>* newNode = new Node<T>(content);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node<T>* temp = head;
    while (temp->next) {

        temp = temp->next;
    }

    temp->next = newNode;
}

template <typename T>
void list<T>::printList()
{
    logs << "uruchomiono funkcje LIST::PRINTLIST" << endl;
    Node<T>* temp = head;

    while (temp) {
        cout << temp->content << endl;
        temp = temp->next;
    }
}
template <typename T>
int list<T>::size()
{
    logs << "uruchomiono funkcje LIST::SIZE" << endl;
    int size = 0;
    Node<T>* temp = head;
    while (temp) {
        size++;
        temp = temp->next;
    }
    return size;
}

template <typename T>
T& list<T>::operator[](int right) const {

    Node<T>* szukany = head;
    for (int i = 0; i < right; i++) {
        szukany = szukany->next;
    }
    return szukany->content;
}

