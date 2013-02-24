/* sandwichList.cpp
 * Comp 15 
 * Spring 2013 
 * Lab 3
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];

	back = 0;
	front = 0;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}

int SandwichList::size()
{
	return (back - front + capacity) % capacity;
}

//function to pop
//remove, do first
Order SandwichList::getNext()
{
	if (!SandwichList::isEmpty()){
		Order rvalue = orders[front];
		front = (++front)%capacity;
		return rvalue;
	}else if (SandwichList::isEmpty()){
		exit(1);
	}
	cerr << "fail whale.\n";
	exit(1);
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::add(const Order& sw)
{
	orders[back] = sw;
	
	if (front == (back + 1)%capacity){
		//cout << "front : " << front << endl;
		//cout << "back: " << back << endl;
		//cout << "(back + 1)%capacity: " << (back + 1)%capacity << endl;
		cout << "front: " << front << " ";
		cout << "Back: " << back << endl;
		expandList();
	}else{
		back = (++back)%capacity;
	}
	
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
	Order* temp_array;
	
	capacity = capacity * 2;
	temp_array = new Order[capacity];
	int i = 0;
	
	while(!isEmpty()){
		//cout << "check 1\n";
		cout << "i: " << i << " ";
		cout << "back: " << back << endl;
		temp_array[i] = getNext();
		cout << "temp_array[i]: " << temp_array[i].orderNbr << endl;
		++i;
		
	};
	
	cout << "check 2\n";
	front = 0;
	back = i;
	
	orders = temp_array;
	for (int k = 0; k < back; ++k){
		cout << "orders[" << k << "]: " << orders[k].orderNbr << endl;
	}
}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



