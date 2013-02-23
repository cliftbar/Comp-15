/*
 * Aaron Tietz
 * Comp 15 
 * Spring 2013 
 * Lab 2
 * Solution example for sandwichList.cpp
 * Note: Ben and I represented size and the starting back value one 
 *		appart - the point it it doesn't matter, what matters is
 *		that the way you do it makes sense and it works
 */


#include "sandwichList_solution.h"

/******

	PUBLIC METHODS

******/


  /* Does: constructor - initializes instance variables
   * Arguments: none
   * Returns: none
   * Calls: none
   * Notes:	relies on INITIAL_SIZE const var declared in .h file
   */
SandwichList::SandwichList(){
  listSize = INITIAL_SIZE;
  orders = new Order[INITIAL_SIZE];	
  back = -1; // I changed this to -1 to reflect how my push function works
  front = 0;
}

  /* Does: returns whether queue is empty or not
   * Arguments: none
   * Returns: true if queue is empty 
   * Calls: SandwichList.size()
   * Notes:	none
   */
bool SandwichList::isEmpty(){
	return size() == 0;
}

  /* Does: returns size of queue
   * Arguments: none
   * Returns: size of queue
   * Calls: none
   * Notes:	none 
   */
int SandwichList::size(){
  return (back - front + listSize + 1) % listSize; 
  // added 1 to reflect my change to back in the constructor
}

  /* Does: returns copy of first Order in queue 
   * Arguments: none
   * Returns: copy of first order in queue
   * Calls: SandwichList.isEmpty()
   * Notes:	calling on an empty queue is an error that results in 
   *  program exit
   */
Order SandwichList::getNext(){
  if(isEmpty()){
    cerr << "tried to pop from an empty queue!\n";
    exit(1);
  }
  return orders[front++];
}

  /* Does: adds a Order to the back of the queue
   * Arguments: reference to an Order 
   * Returns: none
   * Calls: SandwichList.expandList()
   * Notes:	Since back is incremented before copying, back must
   *  start at -1 in the constructor.
   */
void SandwichList::add(const Order& sw){
  if(back == listSize - 1)
    expandList();
    
  orders[++back] = sw;
}

  /* Does: prints given sandwich order 	
   * Arguments: a sandwich order 
   * Returns: none
   * Calls: none
   * Notes:	none
   */
void SandwichList::printOrder(Order s){
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}


/******

	PRIVATE METHODS

******/

  /* Does: doubles the size of the queue array 
   * Arguments: none
   * Returns: none
   * Calls: SandwichList.size()
   * Notes:	none
   */
void SandwichList::expandList(){
  listSize = listSize * 2;
  Order* temp = new Order[listSize];
  int length = size();
  
  for(int i = 0; i < length; i++){
    temp[i] = orders[front++];
  }
  
  delete [] orders;
  orders = temp;
  
  front = 0;
  back = length - 1;
}



