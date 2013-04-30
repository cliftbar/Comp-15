//BogSolver.h
//Created by: Cameron Barclift
//BogSolver reads in a boggle board and solves for every word on the board.
#ifndef BOGSOLVER
#define BOGSOLVER
#include "Dictionary.h"

#include "bog_structs.h"

class BogSolver
{
public:
	//Constructor
	BogSolver();
	//Destructor
	~BogSolver();
	
	//Reads from the standard input stream to build a dictionary
	bool readDict();
	//Reads a Boggle board into the program from the standard input stream
	bool readBoard();
	//Search board for words in dictionary
	bool solve(); 
	//Returns number of words found
	int numWords();
	//Returns the number of words of length len
	int numWords(int len);
	//Returns a list of all words found
	BogWordList* getWords(); 
	//Returns a list of all words of len len
	BogWordList* getWords(int len);
	//Prints all the words in HBF
	void printWords();
	//Prints all the words of lenght len in HBF
	void printWords(int len);
	//Print just the word text, no coordinates
	void listWords(); 
	//Prints just the text of length len words, no coordinates
	void listWords(int len); 	
private:
	//Private data members
	Dictionary dict;
	Letter** board;
	BogWord start_bword;
	int cols;
	int rows;
	int s_pos;
	Linked_Words* word_list;
	int num_words_dups;
	BogWord* bword_array;
	int num_words;
	
	//Private Functions
	//Builds the framework of the board, no values
	bool build_board();
	//Recursive solve function
	bool rec_solve(int c_row, int c_col, BogWord curr_bword, 
		string curr_string, int s_pos);
	//Calls the recursive function on the board cell passed in if the position
	//is valid
	bool p_board_director(BogWord curr_bword, string curr_string, int n_pos,
		int n_row, int n_col);
	//Removes the duplicates from the internal word list
	void rm_dups();
	//converts a BogWord to a string
	string bword_to_string(BogWord bword_in);
	//BogLett array expansion function
	BogLett* expand_word_len(BogWord &bword);
	//Returns a copy of the BogLett array passed in
	BogLett* copy_bw(BogLett* letts_in, int len);
	//Determines if a string contains a 'Q' character
	bool contains_q(string str_in);
	bool add_to_bword_solved(BogWord &curr_bword, int c_row, int c_col);
	bool add_to_lwords_solved(BogWord &curr_bword, string curr_string);
	bool propogation(BogWord curr_bword, string curr_string, int s_pos,
				  int c_row, int c_col);
};

#endif
