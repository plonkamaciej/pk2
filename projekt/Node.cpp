#include "Node.h"

Node* push(Node* head, int key)
{

    Node* node = new Node;
    node->key = key;
    node->next = head;
    return node;
}

Node* constructList(vector<int> const& keys)
{

    // vector<new_minigame> vgame
    //vgame.pushback()...
    //Node *head = constructList(vgame);
    Node* head = nullptr;

    for (int i = keys.size() - 1; i >= 0; i--) {
        head = push(head, keys[i]);
    }

    return head;
}


void printList(Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
        cout << ptr->key << " -> ";
        ptr = ptr->next;
    }

    cout << "nullptr";
}