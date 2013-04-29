//path_finder.cpp
#include "BogSolver.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

BogSolver::BogSolver()
{
	start_bword.numLetts = 0;
	start_bword.letts = NULL;
	s_pos = 0;
	word_list = NULL;
	num_words_dups = 0;
	num_words = 0;
}
BogSolver::~BogSolver()
{
	//destructor
}

bool BogSolver::readDict()
{
	string temp;
	cin >> temp;
	for (int i = 0; i < (int)temp.length(); ++i){
		if (toupper(temp[i]) == 'Q' && toupper(temp[i+1]) == 'U'){
			temp.erase(temp.begin() + i + 1);
		}
		
	}
	
	while (temp != "."){
		if (!dict.insert(temp)){
			return false;
		}
		cin >> temp;
		for (int i = 0; i < (int)temp.length(); ++i){
			if (toupper(temp[i]) == 'Q' && toupper(temp[i+1]) == 'U'){
				temp.erase(temp.begin() + i + 1);
			}
		}
	}
	return true;
}

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

bool BogSolver::solve()
{
	bool ret_value = true;
	
	//loop for every element as a start position
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			ret_value = (true == rec_solve(i, j, start_bword, "", s_pos));
		}
	}
	
	rm_dups();
	
	return ret_value;
}

int BogSolver::numWords()
{
	return num_words;
}

int BogSolver::numWords(int len)
{
	int ret_len = 0;
	
	for (int i = 0; i < num_words; ++i){
		if (bword_array[i].numLetts == len){
			++ret_len;
		}
	}
	
	return ret_len;
}

BogWordList* BogSolver::getWords()
{
	BogWordList* ret_list = NULL;
	if (num_words == 0){
		return ret_list;
	}
	ret_list = new BogWordList;
	ret_list->words = new BogWord[num_words];
	ret_list->numWords = num_words;
	
	for (int i = 0; i < num_words; ++i){
		ret_list->words[i] = bword_array[i];
	}
	
	return ret_list;
}

BogWordList* BogSolver::getWords(int len)
{
	BogWordList* ret_list = NULL;
	int num_of_len = numWords(len);
	
	if(num_of_len == 0){
		return ret_list;
	}
	
	ret_list = new BogWordList[num_of_len];
	ret_list->words = new BogWord[num_of_len];
	ret_list->numWords = num_of_len;
	
	for (int i = 0; i < num_words; ++i){
		if (bword_array[i].numLetts == len){
			ret_list->words[i] = bword_array[i];
		}
	}
	
	return ret_list;
}

void BogSolver::printWords()
{
	for (int i = 0; i < num_words; ++i){
		cout << "< ";
		for (int j = 0; j < bword_array[i].numLetts; ++j){
			cout << bword_array[i].letts[j].c;
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

void BogSolver::printWords(int len)
{
	for (int i = 0; i < num_words; ++i){
		if (bword_array[i].numLetts == len){
			cout << "< ";
			for (int j = 0; j < bword_array[i].numLetts; ++j){
				cout << bword_array[i].letts[j].c;
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
		if(bword_array[i].numLetts == len){
			temp = "";
			for (int j = 0; j < bword_array[i].numLetts; ++j){
				temp += bword_array[i].letts[j].c;
				if (bword_array[i].letts[j].c == 'Q'){
					temp += 'U';
				}
			}
			cout << temp << endl;
		}
	}
}

bool BogSolver::build_board()
{
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

bool BogSolver::rec_solve(int c_row, int c_col, BogWord curr_bword, string
curr_string, int s_pos)
{
	int r_up = c_row - 1;
	int r_down = c_row + 1;
	int c_left = c_col -1;
	int c_right = c_col + 1;
	int n_pos = s_pos + 1;
	Linked_Words* temp;
	bool state = false;
	bool up, up_right, right, d_right, down, d_left, left, up_left;
	
	//cout << "board: " << board[c_row][c_col].l.c;
	curr_string += board[c_row][c_col].l.c;
	curr_bword.numLetts++;
	
	
	if(curr_bword.letts == NULL){
		curr_bword.letts = new BogLett[curr_bword.numLetts];
		curr_bword.letts[curr_bword.numLetts-1].c = board[c_row][c_col].l.c;
		curr_bword.letts[curr_bword.numLetts-1].row =
			board[c_row][c_col].l.row;
		curr_bword.letts[curr_bword.numLetts-1].col =
			board[c_row][c_col].l.col;
	}else {
		curr_bword.letts = expand_word_len(curr_bword);
		curr_bword.letts[curr_bword.numLetts-1] = board[c_row][c_col].l;
	}
	
	
	if (board[c_row][c_col].visited){
		return false;
	}else{
		board[c_row][c_col].visited = true;
	}
	/*
	//can turn into giant "or" with a function
	//cout << "check3" << endl;
	cout << curr_string << endl;
	for (int i = 0; i < curr_bword.numLetts; ++i){
		cout << curr_bword.letts[i].c;
	}
	cout << endl;
	*/
	if (dict.isWord(curr_string) && (int)curr_string.length() >= 3){
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
	}else if (dict.isWord(curr_string) && contains_q(curr_string) &&
		(int)curr_string.length() >= 2){
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
	//cout << "check4" << endl;
	//Propogate in all directions where
	//Sample direction
	//check up
	up = p_board_director(curr_bword, curr_string, n_pos, r_up, c_col);
	//check up, right
	//cout << "check5" << endl;
	up_right = p_board_director(curr_bword,curr_string,n_pos,r_up,c_right);
	//check right
	right = p_board_director(curr_bword,curr_string,n_pos,c_row,c_right);
	//check down, right
	d_right = p_board_director(curr_bword,curr_string,n_pos,r_down,c_right);
	//check down
	down = p_board_director(curr_bword, curr_string, n_pos, r_down, c_col);
	//check down, left
	d_left = p_board_director(curr_bword,curr_string,n_pos,r_down,c_left);
	//check left
	left = p_board_director(curr_bword, curr_string, n_pos, c_row, c_left);
	//check up, left
	up_left = p_board_director(curr_bword,curr_string,n_pos,r_up,c_left);
	
	state = (true ==
		(up||up_right||right||d_right||down||d_left||left||up_left));
	
	//if we get to the end of the function, no further prefixes
	//set element to unvisited
	board[c_row][c_col].visited = false;
	return state;
}



bool BogSolver::p_board_director(BogWord curr_bword, string curr_string, int
n_pos, int n_row, int n_col)
{
	/*
	for (int i = 0; i < curr_bword.numLetts+4; ++i){
			cout << curr_bword.letts[i].c;
		}
	cout << "check6" << endl;
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)){
		cout << dict.isPrefix(curr_string) << endl;
		char board_char = board[n_row][n_col].l.c;
		cout << "board_char: " << board_char << endl;
		cout << "check10" << endl;
		cout << dict.isPrefix(curr_string) << endl;
		string n_string = curr_string;
		cout << dict.isPrefix(n_string) << endl;
		n_string.push_back(board_char);
		cout << n_string << endl;
		cout << dict.isPrefix(n_string) << endl;
		cout << curr_string << " " << board_char << endl;
		cout << n_string << endl;
		cout << n_string.length() << endl;
		if (dict.isPrefix(n_string)){
			cout << "check7" << endl;
			return rec_solve(n_row, n_col, curr_bword, n_string, n_pos);
		}
		cout << "check11" << endl;
	}
	*/
	
	
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)
	&& dict.isPrefix(curr_string + board[n_row][n_col].l.c)){
		//cout << "check7" << endl;
		return rec_solve(n_row, n_col, curr_bword, curr_string, n_pos);
	}
	
	//cout << "check8" << endl;
	return false;
}

void BogSolver::rm_dups(){
	bword_array = new BogWord[num_words_dups];
	bool present = false;
	Linked_Words* iter = word_list;
	
	while(iter != NULL){
		for (int i = 0; i < num_words; ++i){
			if (iter->str_word == bword_to_string(bword_array[i])){
				present = true;
			}
		}
		
		if (!present){
			bword_array[num_words] = iter->word;
			++num_words;
		}else{
			present = false;
		}
		iter = iter->next;
	}
}


string BogSolver::bword_to_string(BogWord bword_in)
{
	string ret_word = "";
	
	for (int i = 0; i < bword_in.numLetts; ++i){
		ret_word += bword_in.letts[i].c;
	}
	
	return ret_word;
}

BogLett* BogSolver::expand_word_len(BogWord &bword)
{
	int len = bword.numLetts;
	BogLett* temp = new BogLett[len];
	//cout << len << endl;
	for (int i = 0; i < len-1; ++i){
		//cout << "woor: " << bword.letts[i].c;
		temp[i].c = bword.letts[i].c;
		temp[i].row = bword.letts[i].row;
		temp[i].col = bword.letts[i].col;
	}
	//cout << endl;
	return temp;
}

BogLett* BogSolver::copy_bw(BogLett* letts_in, int len)
{
	BogLett* temp = new BogLett[len+1];
	
	for (int i = 0; i < len; ++i){
		temp[i] = letts_in[i];
	}
	
	return temp;
}
	
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
	
	
	
	
	
	
	
	
	
	
	
	
	
