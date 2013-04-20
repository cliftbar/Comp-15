//BogValidator.h
//
#ifndef BOGVALIDATOR
#define BOGVALIDATOR
#include "Dictionary.h"
#include "bog_structs.h"
class BogValidator
{
public:
	BogValidator(); // constructor
	
	~BogValidator(); // destructor
	
	bool readDict(); // read in a dictionary
	
	bool readBoard(); // read in a board
	
	bool isValid(string s); // validates one word
	
	void checkWords(); // validates cin
	
	void print_board();
	
private:	
	Dictionary dict; // must use a Dictionary
	// other private methods or data may appear here
	BogLett** board;
	int check_row;
	int check_col;
	unsigned int rows;
	unsigned int cols;
	string check_string;
	void build_board();
	bool on_board(cahr s_in, int s_pos, int c_row, int c_col);
	bool p_board_director(char curr_string, int n_pos, int n_row,
		int n_col);
	
};

#endif