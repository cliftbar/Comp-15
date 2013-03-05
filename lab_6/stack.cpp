#include "stack.h"

Stack::Stack()
{
    head = NULL;
    
}

void Stack::push(BSTNode* n)
{
    Node* temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
    
}

BSTNode* Stack::pop()
{
    //this is a stack we insert,
    //and take from the front
    BSTNode* rVal = head->data;
    
    //point to the head so we can
    //delete it, but move head first
    Node* temp = head;
    head = head->next;
    delete temp;
    return rVal;
}

bool Stack::isEmpty()
{
    return (head == NULL);
}

