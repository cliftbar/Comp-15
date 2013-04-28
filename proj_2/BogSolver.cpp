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
	solve_list = NULL;
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
		if (temp[i] == 'q' && temp[i+1] == 'u'){
			temp.erase(temp.begin() + i + 1);
			//cout << "u removed: " << temp << endl;
		}
		
	}
	
	while (temp != "."){
		if (!dict.insert(temp)){
			return false;
		}
		cin >> temp;
		for (int i = 0; i < (int)temp.length(); ++i){
			if (temp[i] == 'q' && temp[i+1] == 'u'){
				temp.erase(temp.begin() + i + 1);
				//cout << "u removed: " << temp << endl;
			}
		}
	}
	return true;
}

bool BogSolver::readBoard()
{
	//cout << "enter readBoard" << endl;
	string row_string;
	unsigned  int read_cols;
	cin >> rows;
	cin >> cols;
	
	//cout << "rows: " << rows << endl;
	//cout << "cols: " << cols << endl;
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
	
	//print board function
	/*
	cout << "board is: " << endl;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << board[i][j].l.c << " ";
		}
		cout << endl;
	}
	*/
	return true;
}

bool BogSolver::solve()
{
	//cout << "check enter solve" << endl;
	//loop for every element as a start position
	for (int i = 0; i < rows; ++i){
		//cout << "on row: " << i << endl;
		for (int j = 0; j < cols; ++j){
			//cout << "on col: " << j << endl;
			rec_solve(i, j, start_bword, "", s_pos);
		}
	}
	
	if (word_list == NULL){
		return false;
	}else{
		return true;
	}
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

bool BogSolver::rec_solve(int c_row, int c_col, BogWord curr_bword, string
curr_string, int s_pos)
{
	//cout << "check enter rec_solve" << endl;
	//cout << "string in: " << curr_string << endl;
	//cout << "board char: " << board[c_row][c_col].l.c << endl;
	//cout << "board pos: [" << c_row << "][" << c_col << "]" << endl;
	
	int row_up = c_row - 1;
	int row_down = c_row + 1;
	int col_left = c_col -1;
	int col_right = c_col + 1;
	int next_pos = s_pos + 1;
	Linked_Words* temp;
	bool state = false;
	bool up, up_right, right, down_right, down, down_left, left, up_left;
	
	curr_string += board[c_row][c_col].l.c;
	//cout << "curr_string rec: " << curr_string << endl;
	curr_bword.numLetts++;
	if(curr_bword.letts == NULL){
		//cout << "check curr_bword NULL" << endl;
		
		curr_bword.letts = new BogLett[curr_bword.numLetts];
		curr_bword.letts[curr_bword.numLetts-1].c = board[c_row][c_col].l.c;
		curr_bword.letts[curr_bword.numLetts-1].row =
			board[c_row][c_col].l.row;
		curr_bword.letts[curr_bword.numLetts-1].col =
			board[c_row][c_col].l.col;
			
		//cout << "length: " << curr_bword.numLetts << endl;
		//cout << "curr_bword.letts[len-1] NULL added: " <<
			//curr_bword.letts[curr_bword.numLetts-1].c << endl;
	}else {
		//cout << "length: " << curr_bword.numLetts << endl;
		//cout << "curr_bword.letts[len-1] pre-add: " <<
			//curr_bword.letts[curr_bword.numLetts-1].c << endl;
		curr_bword.letts = expand_word_len(curr_bword);
		curr_bword.letts[curr_bword.numLetts-1] = board[c_row][c_col].l;
		//cout << "curr_bword.letts[len-1] post-add: " <<
			//curr_bword.letts[curr_bword.numLetts-1].c << endl;
	}
	
	//cout << "check3" << endl;
	
	//cout << "new string: " << curr_string << endl;
	//cout << "visited: " << board[c_row][c_col].visited << endl;
	
	
	if (board[c_row][c_col].visited){
		//board[c_row][c_col].visited = false;
		return false;
	}else{
		board[c_row][c_col].visited = true;
	}
	
	//cout << "checking if is word" << endl;
	
	if (dict.isWord(curr_string) && (int)curr_string.length() >= 3 ){
		//cout << "check8" << endl;
		temp = new Linked_Words;
		if (temp == NULL){
			cerr << "out of mem" << endl;
			exit(1);
		}
		//cout << "check4" << endl;
		temp->word.numLetts = curr_bword.numLetts;
		temp->word.letts = copy_bw(curr_bword.letts, curr_bword.numLetts);
		temp->str_word = curr_string;
		temp->next = NULL;
		
		//cout << "check5" << endl;
		temp->next = word_list;
		//cout << "check6" << endl;
		word_list = temp;
		++num_words_dups;
		//cout << "check7" << endl;
		
	}
	//cout << "checked if is word" << endl;

	
	//Propogate in all directions where
	//Sample direction
	up = p_board_director(curr_bword, curr_string, next_pos, row_up,
c_col);//check up
	//cout << "check up " << up << endl;//DEBUG
	
	up_right = p_board_director(curr_bword, curr_string, next_pos, row_up,
col_right);
	//check up, right
	//cout << "check up, right " << up_right << endl;//DEBUG
	
	right = p_board_director(curr_bword, curr_string, next_pos, c_row,
col_right);
	//check right
	//cout << "check right " << right << endl;//DEBUG
	
	down_right = p_board_director(curr_bword, curr_string, next_pos, row_down,
col_right);
	//check down, right
	//cout << "check down, right " << down_right<< endl;//DEBUG
	
	down = p_board_director(curr_bword, curr_string, next_pos, row_down,
c_col);
	//check down
	//cout << "check down " << down << endl;//DEBUG
	
	down_left = p_board_director(curr_bword, curr_string, next_pos, row_down,
col_left);
	//check down, left
	//cout << "check down, left " << down_left << endl;//DEBUG
	
	left = p_board_director(curr_bword, curr_string, next_pos, c_row,
col_left);
	//checkleft
	//cout << "check left " << left<< endl;//DEBUG
	
	up_left = p_board_director(curr_bword, curr_string, next_pos, row_up,
col_left);
	//check up, left
	//cout << "check up, left " << up_left << endl;//DEBUG
	
	state = (true ==
		(up||up_right||right||down_right||down||down_left||left||up_left));
	
	//cout << "reached end, current string is " << curr_string << endl;
	//if we get to the end of the function, no further prefixes
	//set element to unvisited
	board[c_row][c_col].visited = false;
	return state;
}

void BogSolver::build_board()
{
	board = new Letter*[rows];
	if(board == NULL){
		cerr << "out of mem" << endl;
		exit(1);
	}
	for (int i = 0; i < rows; ++i){
		board[i] = new Letter[cols];
		if (board[i] == NULL){
			cerr << "out of mem" << endl;
			exit(1);
		}
	}
}

bool BogSolver::p_board_director(BogWord curr_bword, string curr_string, int
n_pos, int n_row, int n_col)
{
	//cout << "n_row: " << n_row << ", n_col: " << n_col << endl;
	//cout << "current string: " << curr_string << endl;
	//cout << "N_pos: " << n_pos << endl;
	//cout << "check_string[n_pos]: " << check_string[n_pos] << endl;
	//cout << "check director" << endl;
	//cout << "board: " <<n_row << n_col << endl;
	//cout << "curr_string: " << curr_string << endl;
	/*
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)
	&& dict.isPrefix(curr_string + board[n_row][n_col].l.c)){
		cout << "check1" << endl;
		return rec_solve(n_row, n_col, curr_bword, curr_string, n_pos);
	}
	*/
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)){
		//cout << "check9" << endl;
		if (dict.isPrefix(curr_string + board[n_row][n_col].l.c)){
			//cout << "check1" << endl;
			return rec_solve(n_row, n_col, curr_bword, curr_string, n_pos);
		}
	}
	//cout << "check2" << endl;
	return false;
}

void BogSolver::printWords()
{
	Linked_Words* iter = word_list;
	//cout << "check1" << endl;
	
	/*
	cout << "linked list with duplicates: " << endl;
	while(iter != NULL){
		//cout << "iter: " << iter << endl;
		cout << bword_to_string(iter->word) << endl;
		iter = iter->next;
	}
	cout << "number of words with duplicates: " << num_words_dups << endl;
	//cout << "get here?" << endl;
	*/
	
	rm_dups();
	/*
	for (int i = 0; i < num_words; ++i){
		cout << bword_to_string(bword_array[i]) << endl;;
	}
	*/
	//cout << "num_words without duplicates: " << num_words << endl << endl;
	
	//cout << "HBF format:" << endl;
	
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
		//cout << "num_words: " << num_words << endl;
		//cout << "array: " << bword_array[num_words] << endl;;
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

BogLett* BogSolver::expand_word_len(BogWord bword)
{
	//cout << "enter expand" << endl;
	int len = bword.numLetts;
	//cout << "numLetts: " << len << endl;
	BogLett* temp = new BogLett[len];
	//cout << temp[len].c << endl;
	/*
	for (int i = 0; i < len; ++i){
		cout << bword.letts[i].c;
	}
	*/
	
	//cout << endl;
	
	for (int i = 0; i < len; ++i){
		temp[i] = bword.letts[i];
	}
	/*
	for (int i = 0; i < len; ++i){
		cout << temp[i].c;
	}
	*/
	//cout << endl;
	
	//cout << "check delete" << endl;
	//delete bword.letts;
	
	//cout << "leave expand" << endl;
	return temp;
}

BogLett* BogSolver::copy_bw(BogLett* letts_in, int len)
{
	//cout << "enter copy" << endl;
	BogLett* temp = new BogLett[len];
	
	for (int i = 0; i < len; ++i){
		temp[i] = letts_in[i];
	}
	
	//cout << "leave copy" << endl;
	return temp;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
