//BogValidator.h
//Created by: Cameron Barclift
#ifndef BOGVALIDATOR
#define BOGVALIDATOR
#include "Dictionary.h"
#include "bog_structs.h"

class BogValidator
{
public:
	BogValidator(); //constructor
	
	~BogValidator(); //destructor
	
	bool readDict(); //read in a dictionary
	
	bool readBoard(); //read in a board
	
	bool isValid(string s); //validates one word
	
	void checkWords(); //validates the user input
	
	void print_board(); //Prints the board
	
private:
	//Private Data members
	Dictionary dict;
	Letter** board;
	int check_row;
	int check_col;
	int rows;
	int cols;
	string check_string;
	int num_said;
	int said_cap;
	BogLettList* start_lett_list;
	string* said_array;
	
	//Private Functions
	void build_board();
	bool contains_q(string str_in);
	bool on_board(string s_in, int s_pos, int c_row, int c_col);
	bool p_board_director(string curr_string, int n_pos, int n_row,
		int n_col);
	bool find_start_letter(char c);
	string to_upper(string s);
	void expand_said();
};

#endif