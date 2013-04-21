
#include "BogValidator.h"
#include "Dictionary.h"
#include <cstdlib>
#include <iostream>
#include <cctype>

BogValidator::BogValidator()
{
	//constructor
	check_row = 0;
	check_col = 0;
	check_string = "";
}

BogValidator::~BogValidator()
{
	//destructor
}

bool BogValidator::readDict()
{
	string temp;
	cin >> temp;
	
	while (temp != "."){
		if (!dict.insert(temp)){
			return false;
		}
		cin >> temp;
	}
	return true;
}

bool BogValidator::readBoard()
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
	bool valid = false;
	check_string = s;
	string rec_string = "";
	rec_string[0] = s[0];
	
	valid = dict.isWord(s);
	
	cout << "found start letter: " << find_start_letter(s[0]) << endl;
	
	if (find_start_letter(s[0]) && s.length() >= 3 && valid){
		valid = valid && on_board(rec_string, 0, check_row, check_col);
	}else{
		valid = 0;
	}
	
	return valid;
}

void BogValidator::checkWords()
{
	string curr_word;
	
	while (cin >> curr_word){
		cout << "current word is: " << curr_word << "." << endl;
		
		curr_word = to_upper(curr_word);
		
		if(isValid(curr_word)){
			cout << "OK " << curr_word << endl;
		}else {
			cout << "NO " << curr_word << endl;
		}
	}
}

bool BogValidator::on_board(string s_in, int s_pos, int c_row,
int c_col)
{
	int row_up = c_row - 1;
	int row_down = c_row + 1;
	int col_right = c_col + 1;
	int col_left = c_col - 1;
	int next_pos = s_pos + 1;
	bool up, up_right, right, down_right, down, down_left, left, up_left;
	s_in += check_string[s_pos];
	//cout << "current s_in: " << s_in[s_pos] << endl;//DEBUG
	//cout << "next_letter fr check_string: " << check_string[next_pos] <<
//endl;
	//cout << "current board place: " << board[c_row][c_col].c << endl;
	if (s_in == check_string){
		return true;
	}
	
	cout << "check up" << endl;//DEBUG
	up = p_board_director(s_in, next_pos, row_up, c_col);	//check up
	
	cout << "check up, right" << endl;//DEBUG
	up_right = p_board_director(s_in, next_pos, row_up, col_right);
	//check up, right
	
	cout << "check right" << endl;//DEBUG
	right = p_board_director(s_in, next_pos, c_row, col_right);
	//check right
	
	cout << "check down, right" << endl;//DEBUG
	down_right = p_board_director(s_in, next_pos, row_down, col_right);
	//check down, right
	
	cout << "check down" << endl;//DEBUG
	down = p_board_director(s_in, next_pos, row_down, c_col);
	//check down
	
	cout << "check down, left" << endl;//DEBUG
	down_left = p_board_director(s_in, next_pos, row_down, col_left);
		//check down, left
	
	cout << "check left" << endl;//DEBUG
	left = p_board_director(s_in, next_pos, c_row, col_left);
		//checkleft
	
	cout << "check up, left" << endl;//DEBUG
	up_left = p_board_director(s_in, next_pos, row_up, col_left);
	//check up, left
	
	bool state = (true ==
(up||up_right||right||down_right||down||down_left||left||up_left));
	cout << "State: " << state << endl;
	return state;
}

bool BogValidator::p_board_director(string curr_string, int n_pos, int  n_row,
		int n_col)
{
	//cout << "n_row: " << n_row << ", n_col: " << n_col << endl;
	//cout << "current string: " << curr_string << endl;
	//cout << "N_pos: " << n_pos << endl;
	//cout << "check_string[n_pos]: " << check_string[n_pos] << endl;
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)
	&& board[n_row][n_col].c == check_string[n_pos]){
		//cout << "check1" << endl;
		return on_board(curr_string, n_pos, n_row, n_col);
	}
	return false;
}

void BogValidator::build_board()
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

bool BogValidator::find_start_letter(char c)
{
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			if (board[i][j].c == c){
				//cout << "c to find: " << c << endl;
				//cout << "Found c at: [" << i << "][" << j << "]" << endl;
				check_row = i;
				check_col = j;
				return true;
			}
		}
	}
	return false;
}

string BogValidator::to_upper(string s)
{
	int s_len = s.length();
	for (int i = 0; i < s_len; ++i){
		s[i] = toupper(s[i]);
	}
	return s;
}