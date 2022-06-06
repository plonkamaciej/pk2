#include "Node.h"
#include "extern.h"

class list {
    Node* head;

public:
    list() { 
        logs << "kontruktor klasy list" << endl;
        head = NULL; 
    }
    ~list();
    void push(dress);
    void printList();
    int size();
    dress& operator[](int) const;
};