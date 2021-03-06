 /* sortedlist.h 
  * Comp 15, Spring 2013
  * Lab 2
  * Name: Cameron Barclift
  */


#ifndef SORTEDLIST_H
#define  SORTEDLIST_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class SortedList{

public:
    /* constructor */
  SortedList();

    /* Adds a new value to the list, preserving ascending sorted order. */
  void insert(int value);


    /* Returns true if list is empty. */
    /* This method is "const", which is a promise to the compiler
        that it won't change the value of any private variables. */
  bool isEmpty() const;

    /* Prints the values in the list in ascending order. */
  void print() const;

    /* copy constructor: used when a brand new SortedList is being made */
  SortedList(SortedList &rhs);

    /* assignment operator: used when a  */
  const SortedList& operator=(const SortedList &rhs);

    /* destructor */
  ~SortedList();
	
private:
  Node* head;
  
    /* deletes all list values and memory*/
  void deleteList();
  
    /* takes a pointer to a Node list and adds all of that list's
        nodes to the current list, this is destructive it removes
       all nodes first */
  void copyNodesFromList(Node* otherList);
};

#endif
