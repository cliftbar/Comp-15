
#include "BogValidator.h"
#include <cstdlib>
#include <iostream>
#include <cctype>

BogValidator::BogValidator()
{
	//constructor
	int check_row = 0;
	int check_col = 0;
}

BogValidator::~BogValidator()
{
	//destructor
}

bool BogValidator::readDict()
{
	string temp;
	
	while (cin >> temp != "."){
		if (!dict.insert(temp)){
			return false;
		}
	}
	return true;
}

bool BogValidator::readBoard()
{
	string row_string;
	
	cin >> rows;
	cin >> cols;
	
	build_board();
	
	for (unsigned int i = 0; i < rows; ++i){
		if(cin >> row_string && row_string.length() == cols){
			for (unsigned int j = 0; j < cols; ++j){
				board[i][j].c = toupper(row_string[j]);
				board[i][j].row = i;
				board[i][j].col = j;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

bool BogValidator::isValid(string s)
{
	check_string = s;
	bool valid = false;
	
	valid = dict.isWord(s);
	
	if (find_start_letter(s[0]) && s.length() >= 3 && valid){
		valid = valid && on_board(s[0], 0, check_row, check_col);
	}
	
	if (valid){
		cout << "OK " << s << endl;
	}else {
		cout << "NO " << s << endl;
	}
	
	return valid;
}

bool BogValidator::on_board(string s_in, int s_pos, int c_row,
int c_col)
{
	int row_up = c_row + 1;
	int row_down = c_row - 1;
	int col_right = c_col + 1;
	int col_left = c_col - 1;
	int next_pos = pos + 1;
	if (s_in == check_string){
		return;
	}
	if (p_board_director(s_in, n_pos, row_up, c_col){
		return true;	//check up
	}else if (p_board_director(s_in, n_pos, row_up, col_right){
		return true;	//check up, right
	}else if (p_board_director(s_in, n_pos, c_row, col_right){
		return true;	//check right
	}else if (p_board_director(s_in, n_pos, row_down, col_right){
		return true;	//check down, right
	}else if (p_board_director(s_in, n_pos, row_down, c_col){
		return true;	//check down
	}else if (p_board_director(s_in, n_pos, row_down, col_left){
		return true;	//check down, left
	}else if (p_board_director(s_in, n_pos, c_row, col_left){
		return true;	//check left
	}else if (p_board_director(s_in, n_pos, row_up, col_left){
		return true;	//check up, left
	}else{
		return false;
	}
}

bool BogValidator::p_board_director(curr_string, n_pos, c_row, c_col)
{
	if ((0 < c_row && c_row < rows) && (0 < c_col && c_col < cols)
	&& board[c_row][c_col] == s_in[n_pos]){
		return on_board(curr_string, n_pos, c_row, c_col);
	}
	return false;
}


void build_board()
{
	board = new BogLett*[rows];
	for (int i = 0; i < rows; ++i){
		board[i] = new BogLett[cols];
	}
}

void BogValidator::print_board()
{
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << board[i][j].c << " ";
		}
		cout << endl;
	}
}
			