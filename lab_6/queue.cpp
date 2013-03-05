#include "queue.h"

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

void Queue::insert(BSTNode* n)
{
    Node* temp = new Node;
    temp->data = n;
    temp->next = NULL;
    
    //empty means tail
    //and head are both NULL
    //this is the only time
    //either can be NULL
    //both become the new node
    if (isEmpty()) {
        head = temp;
        tail = temp;
    }
    
    //if it is not empty, insert
    //at the end.
    
    else {
        tail->next = temp;
        tail = temp;
    }
    
}

BSTNode* Queue::remove()
{
    //this is a queue and we insert at tail,
    //so we take from the front
    BSTNode* rVal = head->data;
    
    //point to the head so we can
    //delete it, but move head first
    Node* temp = head;
    head = head->next;
    delete temp;
    return rVal;
}

bool Queue::isEmpty()
{
    return (head == NULL);
}


