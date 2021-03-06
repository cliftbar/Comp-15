//BogSolver.cpp
//Created by: Cameron Barclift
#include "BogSolver.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

/////////////////////////////Public Functions/////////////////////////////////
//Constructor
BogSolver::BogSolver()
{
	//Initialize private variables
	start_bword.numLetts = 0;
	start_bword.letts = NULL;
	s_pos = 0;
	word_list = NULL;
	num_words_dups = 0;
	num_words = 0;
	rows = 0;
	cols = 0;
	board = NULL;
	bword_array = NULL;
}

//Default destructor
BogSolver::~BogSolver()
{
	//destructor
}

//Reads in a dictionary from the input stream.  All words are converted to
//uppercase.  A '.' is the sentinel for the end of the dictionary.
bool BogSolver::readDict()
{
	string temp;
	cin >> temp;
	
	//If the word contains a q, and the next letter is a u, the u is removed
	for (int i = 0; i < (int)temp.length(); ++i){
		if (toupper(temp[i]) == 'Q' && toupper(temp[i+1]) == 'U'){
			temp.erase(temp.begin() + i + 1);
		}
		
	}
	
	//loop until the sentinel value is reached
	while (temp != "."){
		if (!dict.insert(temp)){
			return false;
		}
		cin >> temp;
		//If the word contains a q, and the next letter is a u, the u
		//is removed
		for (int i = 0; i < (int)temp.length(); ++i){
			if (toupper(temp[i]) == 'Q' && toupper(temp[i+1]) == 'U'){
				temp.erase(temp.begin() + i + 1);
			}
		}
	}
	return true;
}

//Reads in a set amount of data (specified by rows and cols) and builds the
//boggle board.  Rows are read in a a string, and converted to single
//BogLetts, all uppercase
bool BogSolver::readBoard()
{
	string row_string;
	unsigned  int read_cols;
	cin >> rows;
	cin >> cols;
	
	read_cols = cols;
	
	build_board();
	
	for (int i = 0; i < rows; ++i){
		if(cin >> row_string && row_string.length() == read_cols){
			for (int j = 0; j < cols; ++j){
				board[i][j].l.c = toupper(row_string[j]);
				board[i][j].l.row = i;
				board[i][j].l.col = j;
				board[i][j].visited = false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

//Public Sovle Function, sets up for the recursive solver
bool BogSolver::solve()
{
	bool ret_value = true;
	
	//loop calling solver for every element as a start position
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			ret_value = (true == rec_solve(i, j, start_bword, "", s_pos));
		}
	}
	
	//remove duplicates from solutions list
	rm_dups();
	
	return ret_value;
}

//Returns the total number of words
int BogSolver::numWords()
{
	return num_words;
}

//Returns the total number of words of length len.
int BogSolver::numWords(int len)
{
	int ret_len = 0;
	
	for (int i = 0; i < num_words; ++i){
		//True cases: word doesn't contain q and is of length len, or if the
		//word contains q and is of length len-1
		if((!contains_q(bword_to_string(bword_array[i]))
			&& bword_array[i].numLetts == len) ||
			(contains_q(bword_to_string(bword_array[i]))
			&& bword_array[i].numLetts == len-1)){
				
			++ret_len;
		}
	}
	
	return ret_len;
}

//Returns a BogWordList containing every word found.  Returns NULL if no words
//found
BogWordList* BogSolver::getWords()
{
	BogWordList* ret_list = NULL;
	if (num_words == 0){
		return ret_list;
	}
	
	//Assign ret_list new memory
	ret_list = new BogWordList;
	ret_list->words = new BogWord[num_words];
	ret_list->numWords = num_words;
	
	//Loop through ever word in solve list
	for (int i = 0; i < num_words; ++i){
		ret_list->words[i] = bword_array[i];
	}
	
	return ret_list;
}

//Returns a BogWordList containing every word found of length len.  Returns
//NULL if no words found of length len
BogWordList* BogSolver::getWords(int len)
{
	BogWordList* ret_list = NULL;
	int num_of_len = numWords(len);
	
	if(num_of_len == 0){
		return ret_list;
	}
	
	//Assign ret_list new memory
	ret_list = new BogWordList[num_of_len];
	ret_list->words = new BogWord[num_of_len];
	ret_list->numWords = num_of_len;
	
	//Loop through every word in solve list
	for (int i = 0; i < num_words; ++i){
		//True cases: word doesn't contain q and is of length len, or if the
		//word contains q and is of length len-1
		if((!contains_q(bword_to_string(bword_array[i]))
			&& bword_array[i].numLetts == len) || 
			(contains_q(bword_to_string(bword_array[i]))
			&& bword_array[i].numLetts == len - 1)){
			
			ret_list->words[i] = bword_array[i];
		}
	}
	
	return ret_list;
}

//Prints every word in solve list in HBF format
void BogSolver::printWords()
{
	for (int i = 0; i < num_words; ++i){
		cout << "< ";
		for (int j = 0; j < bword_array[i].numLetts; ++j){
			cout << bword_array[i].letts[j].c;
			//If there is a q, add a u afterwards
			if (bword_array[i].letts[j].c == 'Q'){
				cout << 'U' << " ";
			}else{
				cout << " ";
			}
			cout << bword_array[i].letts[j].row << " ";
			cout << bword_array[i].letts[j].col << " ";
		}
		cout << ">" << endl;
	}
}

//Prints every word in solve list of length len in HBF format
void BogSolver::printWords(int len)
{
	for (int i = 0; i < num_words; ++i){
		//True cases: word doesn't contain q and is of length len, or if the
		//word contains q and is of length len-1
		if((!contains_q(bword_to_string(bword_array[i])) &&
			bword_array[i].numLetts == len) ||	
			(contains_q(bword_to_string(bword_array[i]))
			&& bword_array[i].numLetts == len-1)){
			
			cout << "< ";
			for (int j = 0; j < bword_array[i].numLetts; ++j){
				cout << bword_array[i].letts[j].c;
				//If there is a q, add a u afterwards
				if (bword_array[i].letts[j].c == 'Q'){
					cout << 'U' << " ";
				}else{
					cout << " ";
				}
				cout << bword_array[i].letts[j].row << " ";
				cout << bword_array[i].letts[j].col << " ";
			}
			cout << ">" << endl;
		}
	}
}

void BogSolver::listWords()
{
	string temp;
	
	for (int i = 0; i < num_words; ++i){
		temp = "";
		for (int j = 0; j < bword_array[i].numLetts; ++j){
			temp += bword_array[i].letts[j].c;
			//If there is a q in the word, add a u after
			if (bword_array[i].letts[j].c == 'Q'){
				temp += 'U';
			}
		}
		cout << temp << endl;
	}
}

void BogSolver::listWords(int len)
{
	string temp;
	
	for (int i = 0; i < num_words; ++i){
		//True cases: word doesn't contain q and is of length len, or if the
		//word contains q and is of length len-1
		if((!contains_q(bword_to_string(bword_array[i]))
			&& bword_array[i].numLetts == len) ||
			(contains_q(bword_to_string(bword_array[i]))
				&& bword_array[i].numLetts == len-1)){
			
			temp = "";
			for (int j = 0; j < bword_array[i].numLetts; ++j){
				temp += bword_array[i].letts[j].c;
				//If there is a q, add a u after
				if (bword_array[i].letts[j].c == 'Q'){
					temp += 'U';
				}
			}
			cout << temp << endl;
		}
	}
}

//////////////////////////////Private Functions///////////////////////////////

//Builds the framwork of the board
bool BogSolver::build_board()
{
	//If there isn't enough memory, return false
	board = new Letter*[rows];
	if(board == NULL){
		return false;
	}
	
	for (int i = 0; i < rows; ++i){
		board[i] = new Letter[cols];
		if (board[i] == NULL){
			return false;
		}
	}
	return true;
}

//Recursive solve function
bool BogSolver::rec_solve(int c_row, int c_col, BogWord curr_bword, string
curr_string, int s_pos)
{
	bool state = false;
	
	//If board visited, leave, otherwise set board as visited
	if (board[c_row][c_col].visited){
		return false;
	}else{
		board[c_row][c_col].visited = true;
	}
	
	//Add current letter to current string
	curr_string += board[c_row][c_col].l.c;
	//Add 1 to the number of letters in the current BogWord.  This is not
	//accurate until the letter is added in the next if statement
	curr_bword.numLetts++;
	
	bool mem_leave = add_to_bword_solved(curr_bword, c_row, c_col);
	if (!mem_leave){
		return false;
	}
	
	mem_leave = add_to_lwords_solved(curr_bword, curr_string);
	if (!mem_leave){
		return false;
	}
	
	state = propogation(curr_bword, curr_string, s_pos, c_row, c_col);
	//Once we get to the end of the function, no further prefixes
	//set element to unvisited and leave
	board[c_row][c_col].visited = false;
	return state;
}


bool BogSolver::p_board_director(BogWord curr_bword, string curr_string, int
n_pos, int n_row, int n_col)
{
	//If the indicated row and column combination is valid, and the next word
	//that would be formed is a prefix, go to that space.
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)
	&& dict.isPrefix(curr_string + board[n_row][n_col].l.c)){
		return rec_solve(n_row, n_col, curr_bword, curr_string, n_pos);
	}
	
	return false;
}

//Removes duplicate entries from the solve word list to solve word array.  
//There is no preference for any particular path
void BogSolver::rm_dups(){
	bword_array = new BogWord[num_words_dups];
	bool present = false;
	Linked_Words* iter = word_list;
	
	while(iter != NULL){
		//if it is said before, present = true
		for (int i = 0; i < num_words; ++i){
			if (iter->str_word == bword_to_string(bword_array[i])){
				present = true;
			}
		}
		
		//If not said before, add to list
		if (!present){
			bword_array[num_words] = iter->word;
			++num_words;
		}else{
			present = false;
		}
		//Progress iterator
		iter = iter->next;
	}
}

//Converts a BogWord into a string.  Letter coordinates are not included
string BogSolver::bword_to_string(BogWord bword_in)
{
	string ret_word = "";
	
	for (int i = 0; i < bword_in.numLetts; ++i){
		ret_word += bword_in.letts[i].c;
	}
	
	return ret_word;
}

//Expands the dynamic array of a BogLett[]
BogLett* BogSolver::expand_word_len(BogWord &bword)
{
	int len = bword.numLetts;
	BogLett* temp = new BogLett[len];
	
	for (int i = 0; i < len-1; ++i){
		temp[i].c = bword.letts[i].c;
		temp[i].row = bword.letts[i].row;
		temp[i].col = bword.letts[i].col;
	}
	return temp;
}

//returns a copy of the BogLetts[]
BogLett* BogSolver::copy_bw(BogLett* letts_in, int len)
{
	BogLett* temp = new BogLett[len];
	
	for (int i = 0; i < len; ++i){
		temp[i] = letts_in[i];
	}
	
	return temp;
}

//Returns true if the string passed in contains a q
bool BogSolver::contains_q(string str_in)
{
	bool is_q = false;
	
	for (int i = 0; i < (int)str_in.length(); ++i){
		if(str_in[i] == 'Q'){
			is_q = true;
		}
	}
	
	return is_q;
}
	
bool BogSolver::add_to_bword_solved(BogWord &curr_bword, int c_row, int c_col)
{
	//If NULL, give new memory, otherwise expand array and add letter
	if(curr_bword.letts == NULL){
		curr_bword.letts = new BogLett[curr_bword.numLetts];
		if (curr_bword.letts == NULL){
			//not enough memory
			return false;
		}
		curr_bword.letts[curr_bword.numLetts-1].c = board[c_row][c_col].l.c;
		curr_bword.letts[curr_bword.numLetts-1].row =
			board[c_row][c_col].l.row;
		curr_bword.letts[curr_bword.numLetts-1].col =
			board[c_row][c_col].l.col;
	}
	
	curr_bword.letts = expand_word_len(curr_bword);
	curr_bword.letts[curr_bword.numLetts-1] = board[c_row][c_col].l;
	return true;
}
	
bool BogSolver::add_to_lwords_solved(BogWord &curr_bword, string curr_string)
{
	Linked_Words* temp;
	
	//If word is in the dictionary and long enough add to solved list.  Words
	//with a q may be one less than minimum length, as a u will be added.
	if (dict.isWord(curr_string) && ((int)curr_string.length() >= 3 || 
		(contains_q(curr_string) && (int)curr_string.length() >= 2))){
		temp = new Linked_Words;
		if (temp == NULL){
			return false;
		}
		temp->word.numLetts = curr_bword.numLetts;
		temp->word.letts = copy_bw(curr_bword.letts, curr_bword.numLetts);
		temp->str_word = curr_string;
		temp->next = NULL;
		
		temp->next = word_list;
		word_list = temp;
		++num_words_dups;
	}
	return true;
}

bool BogSolver::propogation(BogWord curr_bword, string curr_string, int s_pos,
				  int c_row, int c_col)
{
	int r_up = c_row - 1;
	int r_down = c_row + 1;
	int c_left = c_col -1;
	int c_right = c_col + 1;
	int n_pos = s_pos + 1;
	bool up, u_rgt, right, d_rgt, down, d_left, left, u_left;
	
	//Propogate recursive solver in all directions through director function
	//check up
	up = p_board_director(curr_bword, curr_string, n_pos, r_up, c_col);
	//check up, right
	u_rgt = p_board_director(curr_bword,curr_string,n_pos,r_up,c_right);
	//check right
	right = p_board_director(curr_bword,curr_string,n_pos,c_row,c_right);
	//check down, right
	d_rgt = p_board_director(curr_bword,curr_string,n_pos,r_down,c_right);
	//check down
	down = p_board_director(curr_bword, curr_string, n_pos, r_down, c_col);
	//check down, left
	d_left = p_board_director(curr_bword,curr_string,n_pos,r_down,c_left);
	//check left
	left = p_board_director(curr_bword, curr_string, n_pos, c_row, c_left);
	//check up, left
	u_left = p_board_director(curr_bword,curr_string,n_pos,r_up,c_left);
	//If any are true, return true
	return (true == (up||u_rgt||right||d_rgt||down||d_left||left||u_left));
}
	
	
	
	
	
