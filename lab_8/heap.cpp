#include "heap.h"

Heap::Heap()
{
    
    heap = new int[INIT_SIZE];
    heapSize = 0;
    maxCapacity = 0;
}


Heap::Heap(int list[], int listSize)
{
    
    heap = new int[listSize+1];

    //remember our implementation of a
    //heap starts at 1 not zero, so
    //we store a sentinal value at 0
    //this is not ideal as we could support
    //negative numbers, so it is best to
    //remember 0 is not used
    heap[0]=-1;

    
    for(int i=0; i < listSize; i++)
    {
        heap[i+1] = list[i];
    }
    
    heapSize    = listSize;
    maxCapacity = listSize;

    buildHeap();

}

//doesn't really work
//as the upHeap function
//is not implemented as it
//is nearly the same as the
//down heap funciton

void Heap::insert(int x)
{
    
    if(heapSize+1 >= maxCapacity)
    {
        expand();
    }
    
    //location to insert is heapSize+1 
    //(Recall, 0th location not used)
    heap[heapSize+1] = x;
    heapSize++;
    //heapsize points to index of last element now
    //reheap
    upHeap(heapSize);

}

int Heap::removeMin()
{
	int temp = heap[1];
	heap[1] = heap[heapSize];
	--heapSize;
	downHeap(1);
	return temp;
}

int Heap::size()
{
    return heapSize;
}



void Heap::downHeap(int location)
{
   int c_left = leftChild(location);
   int c_right  = rightChild(location);
   
   cout << "current: " << heap[location] << endl;
   cout << "left child: " << heap[c_left] << endl;
   cout << "right child: " << heap[c_right] << endl;
   
    //recursion
    if (c_right > heapSize && c_left > heapSize){
// 	    cout << "check1\n";
	    return;
    }else if (c_right > heapSize){
// 	    cout << "check2\n";
	    if (heap[c_left] < heap[location]){
// 		    cout << "check3\n";
			heap[0] = heap[c_left];
			heap[c_left] = heap[location];
			heap[location] = heap[0];
			downHeap(c_left);
	    }
    }else if (c_left > heapSize){
	    //Can't happen woo
// 	    cout << "check4\n";
		if (heap[c_right] < heap[location]){
// 			cout << "check5\n";
			heap[0] = heap[c_right];
			heap[c_right] = heap[location];
			heap[location] = heap[0];
			downHeap(c_right);
	    }
    }else {
	    //cout << "check6\n";
		if (heap[c_left] > heap[c_right]){
			//cout << "check7\n";
			if (heap[c_right] < heap[location]){
				//cout << "check8\n";
				heap[0] = heap[c_right];
				heap[c_right] = heap[location];
				heap[location] = heap[0];
				downHeap(c_right);
			}
		}else if (heap[c_right] > heap[c_left]){
			//cout << "check9\n";
			if (heap[c_left] < heap[location]){
				//cout << "check10\n";
				heap[0] = heap[c_left];
				heap[c_left] = heap[location];
				heap[location] = heap[0];
				downHeap(c_left);
			}
		}
    }
//     cout << "parameter fail";
    return;
}

void Heap::upHeap(int location)
{
    //coming soon as it gives away the answer to heapify
    //they are the same funciton
}   

void Heap::buildHeap()
{
	for (int i = parent(heapSize); i > 0; --i){
		cout << "i: " << i << endl;
		downHeap(i);
	}
}

int Heap::leftChild(int index)
{
    return index*2;
}
int Heap::rightChild(int index)
{
    return index*2+1;

}
int Heap::parent(int index)
{
    return index/2;
}


//same old expand funciton, copying
//each element preserves the heap property
void Heap::expand()
{
    int *temp = new int[maxCapacity*2];
    
    for (int i = 0; i < heapSize+1; i++) {
        temp[i] = heap[i];
    }
    maxCapacity = maxCapacity*2;
    
    delete[] heap;
    heap = temp;
}

