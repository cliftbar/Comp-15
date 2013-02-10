
#include "sequence.h"
#include <iostream>

using namespace std;

int main()
{
	Sequence_List odd_sequence;
	Sequence_List even_sequence;
	
	int odd_num;
	int even_num;
	bool exit;
	bool read_in;
	
	//odd_sequence
	do{
	cout << "Enter odd number: \n";
	cin >> odd_num;
	
	odd_sequence.insert(odd_num);
	
	cout << "Enter 1 to finish odd sequence. \n";
	cin >> exit;
	
	}while (!exit);
	
	cout << "You entered: \n";
	odd_sequence.print();
	
	//even_sequence
	do{
		cout << "Read in number? \n";
		cin >> read_in;
		
		if (read_in) {
			cout << "Enter even number: \n";
			cin >> even_num;
			even_sequence.insert(even_num);
		}
	
		cout << "Enter 1 to finish even sequence. \n";
		cin >> exit;
	
	}while (!exit);
	
	cout << "You entered: \n";
	even_sequence.print();
	
	//odd and even concatenated
	cout << "odd + even\n";
	odd_sequence.concatenation(even_sequence);
	odd_sequence.print();
	
	//sequence concatenated self
	cout << "odd + odd\n";
	odd_sequence.concatenation(odd_sequence);
	odd_sequence.print();
	
return 0;	
}