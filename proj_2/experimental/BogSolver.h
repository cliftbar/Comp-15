//path_finder.h
//Follows all possible paths for a starting word, and list all valid words
//those paths.
#ifndef BOGSOLVER
#define BOGSOLVER
#include "Dictionary.h"

#include "bog_structs.h"

class BogSolver
{
public:
	BogSolver();
	~BogSolver();
	bool readDict();
	bool readBoard();
	bool solve(); // search board for words in dict
	int numWords(); // returns number of words found
	int numWords(int len); // number of words of length len
	BogWordList* getWords(); // returns all words found
	BogWordList* getWords(int len); // returns words of len len
	void printWords(); // print all words in HBF
	void printWords(int len); // print len-length words in HBF
	void listWords(); // print just the text, no coords
	void listWords(int len); 	// just the text, no coords
private:
	Dictionary dict; // must use a Dictionary
	// other private methods or data may appear here
	Letter** board;
	BogWord start_bword;
	int cols;
	int rows;
	int s_pos;
	Linked_Words* word_list;
	int num_words_dups;
	BogWord* bword_array;
	int num_words;
	
	bool build_board();
	bool rec_solve(int c_row, int c_col, BogWord curr_bword, 
		string curr_string, int s_pos);
	bool p_board_director(BogWord curr_bword, string curr_string, int n_pos,
		int n_row, int n_col);
	void rm_dups();
	string bword_to_string(BogWord bword_in);
	BogLett* expand_word_len(BogWord &bword);
	BogLett* copy_bw(BogLett* letts_in, int len);
	bool contains_q(string str_in);
};

#endif