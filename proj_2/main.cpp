
#include <iostream>
#include "Dictionary.h"
#include "BogValidator.h"

int main()
{
	BogValidator val;
	
	val.readDict();
	cout << "check read dict" << endl;
	val.readBoard();
	cout << "check read board" << endl;
	
	val.print_board();
	
	val.checkWords();
	cout << "words checked" << endl;
	
	
	
	
	
	return 0;
}