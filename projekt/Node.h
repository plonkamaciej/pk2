#include "header.h"
#include "extern.h"

template <typename T>
class Node
{
public:
    T content;
    Node<T>* next;    
   
    Node(T content)
    {   
        logs << "kontruktor klasy Node" << endl;
        this->content = content;
        this->next = NULL;
    }
};

