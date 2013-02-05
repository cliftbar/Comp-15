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
	cerr << "v: " << v << endl;//DEBUG CODE*/
	
	//empty case
	if(head == NULL){
		cerr << "empty case entered" << endl;//DEBUG CODE*/
		head = np;
		cerr << "empty case run" << endl;//DEBUG CODE*/
		cerr << "np->data: " << np->data << endl;//DEBUG CODE*/
		return;
	}

	//front case
	if (iter != NULL && iter->data >= np->data){
		cerr << "front case entered" << endl;//DEBUG CODE*/
		np->next = head;
		head = np;
		cerr << "front case run" << endl;//DEBUG CODE*/
		cerr << "np->data: " << np->data << endl;//DEBUG CODE*/
		return;
	}
	
	//middle case
	while(iter != NULL && iter->data < np->data){
		cerr << "middle case entered" << endl;//DEBUG CODE*/
		prev = iter;
		iter = iter->next;
		cerr << "middle case run" << endl;//DEBUG CODE*/
	}
	
	if(iter != NULL){
		cerr << "middle pt. 2 case entered" << endl;//DEBUG CODE*/
		prev->next = np;
		np->next = iter->next;
		cerr << "np->data: " << np->data << endl;//DEBUG CODE*/
		cerr << "middle case pt. 2 run" << endl;//DEBUG CODE*/
		return;
	}
	
	//end case
	if(iter == NULL){
		cerr << "end case entered" << endl;//DEBUG CODE*/
		prev = prev->next;
		prev = np;
		np->next = iter;
		cerr << "end case run" << endl;//DEBUG CODE*/
		cerr << "np->data: " << np->data << endl;//DEBUG CODE*/
		return;
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

