#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>


#ifndef _NODE
#define _NODE


using namespace std;

//tree node defined here
//stack, queue and tree
//need this defintions

struct BSTNode {
		int value;
		BSTNode* left;
		BSTNode* right;
};

//This is a node for
//a linked list implementation
//the data will be a pointer to
//a node in the tree. It is
//used in both stack and queue

struct Node {
    BSTNode* data;
    Node* next;
};

#endif