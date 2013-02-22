 /* sortedlist.cpp 
  * Comp 15, Spring 2013
  * Lab 1
  * Name: Cameron Barclift
  */
  
#include "sortedlist.h"

/******

PUBLIC METHODS

******/

 /* Does: Constructor, sets head to NULL
  * Arguments: none
  * Returns: none
  * Calls: none
  * Notes: none
  */
SortedList::SortedList(){
	head = NULL;
}


 /* Does: prints the values of the list in order starting at the head
  * Arguments: none
  * Returns: none
  * Calls: none
  * Notes: this method is "const", which is a promise to the compiler
  *  that it won't change the value of any private variables.
  */
void SortedList::print() const{
  Node* iterator = head;
  while(iterator != NULL){
    cout << iterator->data << " ";
    iterator = iterator->next;
  }
  cout << endl;
}

 /* Does: returns whether or not list is empty
  * Arguments: none
  * Returns: true if list is empty
  * Calls: none
  * Notes: this method is "const", which is a promise to the compiler
  *  that it won't change the value of any private variables.
  */
bool SortedList::isEmpty() const{
  if(head == NULL)
    return true;
  else
    return false;
}

 /* Does: 
  * Arguments: 
  * Returns: 
  * Calls: 
  * Notes: 
  */
void SortedList::insert(int v){

//your code here and your comment above
//inserting an element, head is a member of a class

	Node* np = new Node;
	Node* iter = head;
	Node* prev = head;

	np->data = v;
	np->next = NULL;
	cerr << "v: " << v << endl;//DEBUG CODE*/
	
	if (isEmpty()){
		cerr << "list empty\n";
		head = np;
		prev = np;
		return;
	}else if (iter->data > np->data){
		cerr << "front case, single list\n";
		np->next = iter;
		head = np;
		return;
	}else{
		cerr << "middle/end\n";
		while((iter->data < np->data) && iter->next != NULL){
			prev = iter;
			iter = iter->next;
			cerr << iter->data << " " << np->data << endl;
		}
		cerr << "found place\n";
		if (iter->next != NULL){
			cerr << "iter->next != NULL\n";
			prev = np;
			np->next = iter;
			return;
		}else if (iter->next == NULL){
			cerr << "iter->next = NULL\n";
			prev->next = np;
			np->next = iter;
			return;
		}
	}
}

 /* Does: copy constructor
  * Arguments: 
  * Returns: 
  * Calls: insertNodesFromList
  * Notes: This is a constructor, so don't forget to initialize 
  *  head to NULL! Otherwise what would happen when you call
  *  insertNodesFromList?
  */
SortedList::SortedList(SortedList &rhs){

	//your code here and your comment above 
}

 /* Does: Assignment Operator
  * Arguments: 
  * Returns: 
  * Calls: SortedList::deleteList, SortedList::insertNodesFromList
  * Notes: This is not a constructor - a SortedList has already been
  *  made when you call this.  So, no need to set head to NULL here.
  *  In fact, that would be a mistake if head was pointing to a node.
  */
const SortedList& SortedList::operator=(const SortedList &rhs){	
//check to make sure that you don't overwrite yourself
//with yourself...just in case someone does list1 = list1;
  if (this != &rhs) {
    
  }
  
    //unlike copy constructor, return this (a pointer to yourself)
  return *this;
}

 /* Does: destructor - deletes any nodes in list 
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

 /* Does: 
  * Arguments: 
  * Returns: 
  * Calls: 
  * Notes: Remember to set head to NULL when you're done!
  */
void SortedList::deleteList(){

  // your code here and comment above
    

    
}

 /* Does: 
  * Arguments: 
  * Returns: 
  * Calls: 
  * Notes: 
  */
void SortedList::copyNodesFromList(Node* otherList){

  // your code here and comment above
}

