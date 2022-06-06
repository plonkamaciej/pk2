#include "list.h"
#include "header.h"
#include "extern.h"


void list::push(dress content)
    {
        logs << "uruchomiono funkcje LIST::PUSH" << endl;
        Node* newNode = new Node(content);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {

            temp = temp->next;
        }

        temp->next = newNode;
    }

    void list::printList()
    {
        logs << "uruchomiono funkcje LIST::PRINTLIST" << endl;
        Node* temp = head;

        while (temp) {
            cout << temp-> content << endl;
            temp = temp->next;
        }
    }

    int list::size()
    {
        logs << "uruchomiono funkcje LIST::SIZE" << endl;
        int size = 0;
        Node* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    dress& list::operator[](int right) const {

            Node * szukany = head;
            for (int i = 0; i < right; i++) {
               szukany = szukany->next;
            }
            return szukany->content;
    }

    list::~list()
    {
        logs << "uruchomiono destruktor listy" << endl;

        Node* current = head;
        while (current != 0) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = 0;
    }

