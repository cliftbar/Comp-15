 /* sortedlist_solution.h 
  * Comp 15, Spring 2013
  * Lab 1
  * Name: Aaron Tietz
  */


#ifndef SORTEDLIST_H
#define  SORTEDLIST_H

#include<iostream>
#include<string>
#include<fstream>

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
  bool insert(int value);

    /* Removes and returns the minimum list value.
        It is an error to call removeMin on an empty list. */
  int removeMin();

    /* Returns true if list is empty. */
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
  
    /* deletes all list values */
  void deleteList();
  
    /* takes a pointer to a Node list and adds all of that list's
        nodes to the current list */
  void insertNodesFromList(Node* otherList);
};

#endif
