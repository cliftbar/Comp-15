#include "sandwichList.h"
#include <cstdlib>


SandwichList::SandwichList()
{
	listSize = initialSize;
	orders = new Order[initialSize];

	
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

	return (back - front + listSize) % listSize;

}

//function to pop
Order SandwichList::getNext()
{


//BEGIN CUT 1

	if(isEmpty())
	{
		cout << "list is empty" << endl;
		exit(1);
	}
	

	int temp = front;
	front = (front+1)%listSize;
	
	return orders[temp];

		
		
//END CUT 1

}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::add(const Order& sw)
{

//BEGIN CUT 2


	if(isEmpty())
	{

	//cout << "adding to empty" << endl;

	orders[0] = sw;

	back = 1;
	front = 0;



	}

	else
	{

		if(size() != listSize-1)
		{
			orders[back] =  sw;
			back = (back+1) % listSize;
			
		
			
		}
	
		else
		{
			expandList();
			orders[back] = sw;
			back = (back+1) % listSize;
			
		
		

		}

	}

//END CUT 2
	
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{

// BEGIN CUT 3

	int tempS = listSize * 2;
	Order* temp = new Order[tempS];
	int i= 0;

	while(!isEmpty())
	{
		temp[i] = getNext();
		i++;
	}

	delete [] orders;
	orders = temp;
	listSize = tempS;
	front = 0;
	back = i;

// END CUT 3

}

void SandwichList::printOrder(Order s)
{

	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
	
}



