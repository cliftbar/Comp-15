
 /* main.cpp
  * Comp 15, Spring 2013
  * Lab 1
  * Name: Cameron Barclift
  */


#include "sortedlist.h"
#include <iostream>
#include <fstream>
using namespace std;

/* Reads the file and inserts the
   element into the list, l, that was passed in. */
void readFile(SortedList &l, char filename[]){
  int temp;
  ifstream fin;
  fin.open(filename);
  while (!fin.eof()) {
    fin >> temp;
    if(!fin.eof())
	  l.insert(temp);
  }
}


int main(){
	SortedList l1;
	SortedList l2;
	char file1[] = "input1.txt";
	char file2[] = "input2.txt";
	
	//tests the insert function.
	readFile(l1, file1);
	readFile(l2, file2);
	
	cout << "List 1\n";
	l1.print();
	cout << "It should be \n";
	cout << "1 3 3 4 4 6 7 9 9 9 12 12 22 55 56 78\n\n"; 

	cout << "List 2\n";
	l2.print();
	cout << "It should be \n";
	cout << "4 8 15 16 23 42\n";
	
	// now test the copy constructor,
	// remove the following comment after you implement it

	SortedList l3 = l1;
	l1.insert(21);
	l3.insert(54);
	
	cout << "List 1 is now:\n";
	l1.print();
	cout << "It should be \n";
	cout << "1 3 3 4 4 6 7 9 9 9 12 12 21 22 55 56 78\n\n";
	
	cout << "List 3 is:\n";
	l3.print();
	cout << "It should be \n";
	cout << "1 3 3 4 4 6 7 9 9 9 12 12 22 54 55 56 78\n\n";


	// now test the assignment operator,
	// remove the following comment after you implement it
	

	SortedList l4;
	l4 = l2;
	l2.insert(33);
	l4.insert(1);
	
	cout << "List 2 is now:\n";
	l2.print();
	cout << "It should be \n";
	cout << "4 8 15 16 23 33 42\n\n";
	
	cout << "List 4 is:\n";
	l4.print();
	cout << "It should be \n";
	cout << "1 4 8 15 16 23 42\n\n";
	
	
	//Special cases of assignment and copy
	//copying a null list each time.
	
	SortedList l5;
	l1 = l5;
	SortedList l6 = l5;
	
	
	l5.insert(7);
	l5.insert(2);
	l6.insert(8);
	l6.insert(9);
	l1.insert(4);
	l1.insert(2);
	l1.insert(5);
	
	cout << "List 5 is:\n";
	l5.print();
	cout << "It should be \n";
	cout << "2 7\n\n";
	
	cout << "List 6 is:\n";
	l6.print();
	cout << "It should be \n";
	cout << "8 9\n\n";
	
	cout << "List 1 is now:\n";
	l1.print();
	cout << "It should be \n";
	cout << "2 4 5\n\n";


	return 0;
}
