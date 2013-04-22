//path_finder.h
//Follows all possible paths for a starting word, and list all valid words
//those paths.

class BogSolver
{
public:
	BogSolver();
	̃BogSolver();
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
	int cols;
	int rows;
	BogWordList* word_list;
	BogWordList* eof_list
	void rec_solve(int c_row, int c_col, string curr_string);
	
	
}


