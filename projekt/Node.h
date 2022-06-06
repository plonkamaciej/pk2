#include "header.h"
#include "extern.h"

using namespace std;

class Node
{
public:
    dress content;        
    Node* next;    
   
    Node(dress content)
    {   
        logs << "kontruktor klasy Node" << endl;
        this->content = content;
        this->next = NULL;
    }
};

