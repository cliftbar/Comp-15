#include <iostream>
#include "Dictionary.h"
#include "BogSolver.h"

int main()
{
	BogSolver solver;
	solver.readDict();
	//cout << "check read dict" << endl;
	solver.readBoard();
	//cout << "check read board" << endl;
	solver.solve();
	//cout << "check solve" << endl;
	solver.printWords();
	
	return 0;
}
