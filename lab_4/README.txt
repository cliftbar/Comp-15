Topics: linked lists, copy constructors/=operator
Big Idea: abstract data types
	abstract: some details on how it does it are hidden, what it does is the important part
today: a sorted list
	what can it do?
		1. create one
		1.5 add item
		2. remove an item
		3. search
		4. copy
		5. print

how do we build one?
Array?
	-add 7=> 7
	-add 12=> 7->12
	- add 2...have to move lots of stuff around for =>2->7->12 shoot me
so we do a linked list
-some reminders on LLists
	-print linked lists:
//print function
void print(Node* n)
{
	Node* iter = head;
	while(iter != NULL){
		cout << iter->data;
		iter = iter->next;
	}
}

//to find a node in a list
bool isInList(Node* h, int f)
{
	Node* iter = h;
	while (iter != NULL){
		if(iter->data == f){
			return true;
		}else{
			iter = ier->next;
		}
	}
	return false;
}

//inserting an element, head is a member of a class
void add(int v)
{
	Node* np = new Node;
	Node* iter = head;
	Node* prev = head;

	np->data = 7;
	
	//strange empty case
	if(head == NULL){
		head = np);
	}

	//front of the list
	if (//at front){
		np->next = head;
		head = np;
	}
	
	//run through middle
	while(iter != NULL){
		if(iter->data < np->data){
			prev = iter;
			iter = iter.next;
		}else if(iter->data >= np->data){
			prev.next = np;
			np->next = iter->next;
		}
	}
	
	//weird end case
	prev = prev.next;
	prev = np;
	np->next = iter;
}



