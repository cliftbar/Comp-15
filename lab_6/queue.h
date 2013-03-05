#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>

#include "node.h"

using namespace std;


class Queue
{
    public:
    
        //default constructor
        //set head to NULL
        Queue();
    
        //standard interface to a queue
        void insert(BSTNode* v);
        BSTNode* remove();
        bool isEmpty();
    
    private:
        Node* head;
        Node* tail;
    
};

