
#include "sequence.h"
#include <iostream>

using namespace std;

int main()
{
	Sequence_List odd_sequence;
	Sequence_List even_sequence;
	Sequence_List single_sequence;
	
	int odd_num;
	int even_num;
	bool exit;
	bool read_in;
	
	cout << "single_sequence value: 10\n";
	single_sequence.insert(10);
	
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
	
	cout << "odd remove: " << odd_sequence.remove() << endl;
	odd_sequence.print();
	
	
	//even and odd concatenated
	cout << "even + odd\n";
	even_sequence.concatenation(odd_sequence);
	even_sequence.print();
	
	//sequence concatenated self
	cout << "odd + odd\n";
	odd_sequence.concatenation(odd_sequence);
	odd_sequence.print();
	
	//empty sequence concatenated self
	cout << "even + even\n";
	even_sequence.concatenation(even_sequence);
	even_sequence.print();
	
	//odd and single concatenated
	cout << "odd + single\n";
	odd_sequence.concatenation(single_sequence);
	odd_sequence.print();
	
	//single and odd concatenated
	cout << "single + odd\n";
	single_sequence.concatenation(odd_sequence);
	single_sequence.print();
	
	//even and single concatenated
	cout << "even + single\n";
	even_sequence.concatenation(single_sequence);
	even_sequence.print();
	
	//single and even concatenated
	cout << "single + even\n";
	single_sequence.concatenation(even_sequence);
	single_sequence.print();

	//single and single concatenated
	cout << "single + single\n";
	single_sequence.concatenation(single_sequence);
	single_sequence.print();
	
return 0;	
}