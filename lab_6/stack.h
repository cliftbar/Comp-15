#include "node.h"

class Stack
{
public:
    
    //default constructor
    //set head to NULL
    Stack();
    
    //standard interface to a queue
    void push(BSTNode* v);
    BSTNode* pop();
    bool isEmpty();
    
private:
    Node* head;
    
};

	


