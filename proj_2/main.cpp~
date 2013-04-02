//main.cpp

#include "dictionary.h"
#include "node.h"
#include <iostream>
using namespace std;

int main()
{
	string input;
	Dictionary my_dictionary;
	bool gogo = true;
	
	while(gogo){
		cout << "input a string: ";
		cin >> input;
		
		my_dictionary.insert(input);
		
		cout << "continue? ";
		cin >> gogo;
	}
	
	cout << "entering empty string" << endl;
	my_dictionary.insert("");
	
	cout << "enter a prefix now? ";
	cin >> gogo;
	
	while(gogo){
		cout << "what prefix: ";
		cin >> input;
		
		if (my_dictionary.isPrefix(input)){
			cout << "Word is a prefix" << endl;
		}else {
			cout << "Darn, word is not a prefix" << endl;
		}
		
		cout << "continue? ";
		cin >> gogo;
	}
	
	cout << "Is empty string a prefix? " << my_dictionary.isWord("");
	
	cout << "find a word now? ";
	cin >> gogo;
	
	while(gogo){
		cout << "what word: ";
		cin >> input;
		
		if (my_dictionary.isWord(input)){
			cout << "Word is in dictionary" << endl;
		}else {
			cout << "Darn, word is not in dictionary" << endl;
		}
		
		cout << "continue? ";
		cin >> gogo;
	}

	cout << "does empty string exist? " << my_dictionary.isWord("") << endl;
	
	my_dictionary.print_all_words();
	
	return 0;
}