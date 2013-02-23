/*
 * Aaron Tietz
 * Comp 15 
 * Spring 2013 
 * Lab 1
 * Solution example for sortedlist.cpp
 */

#include "sortedlist_solution.h"
#include <iostream>
using namespace std;


/******

PUBLIC METHODS

******/

 /* Does: Constructor 	
  * Returns: none
  * Calls: none
  * Notes: none
  */
SortedList::SortedList(){
  head = NULL;
}

 /* Does: Copy Constructor
  * Arguments: 1. reference to SortedList instance to copy from
  * Returns: none
  * Calls: SortedList::isEmpty, SortedList::insertNodesFromList
  * Notes: deletes current list, if any, and creates a copy of 
  *  list in rhs
  */
SortedList::SortedList(SortedList &rhs){
  head = NULL;  
  if(!rhs.isEmpty())
    insertNodesFromList(rhs.head);
}

 /* Does: assignment operator
  * Arguments: 1. reference to SortedList instance to copy from
  * Returns: address of class instance copied to (this)
  * Calls: SortedList::isEmpty, SortedList::deleteList, 
  *  SortedList::insertNodesFromList
  * Notes: Deletes current list, if any, and creates a copy of 
  *  list in rhs.  Does nothing if rhs and this are the same.
  */
const SortedList& SortedList::operator=(const SortedList &rhs){
  if(this != &rhs){     
    if(!isEmpty())
      deleteList();
    if(!rhs.isEmpty())
      insertNodesFromList(rhs.head);
  }
  return *this;
}

 /* Does: inserts a new node into the list pointed to by
  *  head, preserving ascending sorted order	
  * Arguments: int - the data to be given to the new node
  * Returns: none
  * Calls: none
  * Notes: Handles all four possible scenarios (inserting into an 
  *  empty list, inserting into an non-empty list in the front,
  *  middle, and at the end.
  */
bool SortedList::insert(int v){
  Node* newNode = new Node;
  newNode->data = v;
  newNode->next = NULL;
  
	// check for empty list
  if(head == NULL){
    head = newNode;
  }
    // check if node to insert is new low data
  else if(head->data >= v){
  	newNode->next = head;
  	head = newNode;
  }
    // else node must be inserted in middle or at end
  else{
    Node* currentNode = head;
      // stop when next node data > the data to insert, 
      //  or when you're on the last node of the list
    while(currentNode->next != NULL && currentNode->next->data < v){
      currentNode = currentNode->next;
    }	 
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }
  return true;
 }

 /* Does: deletes first node, returning its data
  * Arguments: none
  * Returns: data held in first node
  * Calls: SortedList::isEmpty()
  * Notes: exits with an error message if called on an empty list
  */
int SortedList::removeMin(){
  if(isEmpty()){
    cerr << "tried to remove from an empty list!\n";
    exit(1);	
  }
  
  Node* temp = head;
  int v = head->data;
  head = head->next;
  delete temp;
  return v;	
}


 /* Does: prints datas in list	pointed to by head
  * Arguments: none
  * Returns: none
  * Calls: none
  * Notes: none
  */
void SortedList::print() const{
  Node* iterator = head;
  while(iterator != NULL){
    cout << iterator->data << " ";
	iterator = iterator->next;
  }
}

 /* Does: determines if list pointed to by head is empty
  * Arguments: none
  * Returns: true if list is empty
  * Calls: none
  * Notes: none
  */
bool SortedList::isEmpty() const{
  return head == NULL;
}

 /* Does: Descructor - deletes any nodes pointed to by head 
  * Arguments: none
  * Returns: none
  * Calls: SortedList::deleteList
  * Notes: none
  */
SortedList::~SortedList(){
  deleteList();
}


/******

	PRIVATE METHODS

******/

 /* Does: assigns head a copy of the list passed in	
  * Arguments: Node* that points to the front of the list 
  *  to copy from
  * Returns: none
  * Calls: SortedList::insert
  * Notes: none
  */
void SortedList::insertNodesFromList(Node* otherList){
  Node* temp = otherList;
  while(temp != NULL){
    insert(temp->data);
    temp = temp->next;
  }
}

 /* Does: deletes any nodes pointed to by head 
  * Arguments: none
  * Returns: none
  * Calls: none
  * Notes: none
  */
void SortedList::deleteList(){
  Node* temp = head;
  Node* remover;
  while(temp != NULL){
    remover = temp;
    temp = temp->next;
    delete remover;
  }	
  head = NULL;
}





