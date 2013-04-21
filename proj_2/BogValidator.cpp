
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
	word_list = NULL;
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
				board[i][j].visited = false;
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
	bool in_dict = false;
	bool in_board = false;
	check_string = s;
	string rec_string = "";
	bool found_start = find_start_letter(s[0]);
	rec_string[0] = s[0];
	BogLettList* list_iter = word_list;
	
	
	
	if(list_iter == NULL){
		//cout << "list_iter NULL" << endl;
	}
	
	if(word_list == NULL){
		//cout << "word_list NULL" << endl;
	}
	
	
	in_dict = dict.isWord(s);
	
	//cout << "found start letter: " << found_start << endl;
	
	if (found_start && s.length() >= 3 && in_dict){
		//cout << "check3" << endl;
		while (list_iter != NULL){
			//cout << "in while" << endl;
			check_row = list_iter->letter.row;
			check_col = list_iter->letter.col;
			in_board = on_board(rec_string, 0,check_row, check_col);
			if (in_board){
				break;
			}
			list_iter = list_iter->next;
			//cout << "in_board: " << in_board << endl;
		}
	}else{
		//cout << "check2" << endl;
		in_board = false;
	}
		
		
	while(word_list != NULL){
		list_iter = word_list;
		word_list = word_list->next;
		delete list_iter;
	}
	
	if(list_iter == NULL){
		//cout << "list_iter NULL" << endl;
	}
	
	if(word_list == NULL){
		//cout << "word_list NULL" << endl;
	}
		
	//cout << "valid: " << (in_board && in_dict) << endl;
	return (in_board && in_dict);
}

void BogValidator::checkWords()
{
	string curr_word;
	
	while (cin >> curr_word){
		//cout << "current word is: " << curr_word << "." << endl;
		
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
	
	if (board[c_row][c_col].visited){
		board[c_row][c_col].visited = false;
		//cout << "visited" << endl;
		return false;
	}else {
		//cout << "NOT visited" << endl;
		board[c_row][c_col].visited = true;
	}
	
	if (s_in == check_string){
		board[c_row][c_col].visited = false;
		return true;
	}
	
	up = p_board_director(s_in, next_pos, row_up, c_col);	//check up
	//cout << "check up " << up << endl;//DEBUG
	
	up_right = p_board_director(s_in, next_pos, row_up, col_right);
	//check up, right
	//cout << "check up, right " << up_right << endl;//DEBUG
	
	right = p_board_director(s_in, next_pos, c_row, col_right);
	//check right
	//cout << "check right " << right << endl;//DEBUG
	
	down_right = p_board_director(s_in, next_pos, row_down, col_right);
	//check down, right
	//cout << "check down, right " << down_right<< endl;//DEBUG
	
	down = p_board_director(s_in, next_pos, row_down, c_col);
	//check down
	//cout << "check down " << down << endl;//DEBUG
	
	down_left = p_board_director(s_in, next_pos, row_down, col_left);
		//check down, left
	//cout << "check down, left " << down_left << endl;//DEBUG
	
	left = p_board_director(s_in, next_pos, c_row, col_left);
		//checkleft
	//cout << "check left " << left<< endl;//DEBUG
	
	
	up_left = p_board_director(s_in, next_pos, row_up, col_left);
	//check up, left
	//cout << "check up, left " << up_left << endl;//DEBUG
	
	bool state = (true ==
(up||up_right||right||down_right||down||down_left||left||up_left));
	//cout << "State: " << state << endl;
	
	board[c_row][c_col].visited = false;
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
	bool present = false;
	BogLettList* temp = word_list;
	
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			if (board[i][j].c == c){
				//cout << "c to find: " << c << endl;
				//cout << "Found c at: [" << i << "][" << j << "]" << endl;
				if (word_list == NULL){
					//cout << "word_list NULL" << endl;
					word_list = new BogLettList;
					temp = word_list;
				}else {
					//cout << "temp not NULL" << endl;
					temp->next = new BogLettList;
					temp = temp->next;
				}
				temp->next = NULL;
				temp->letter = board[i][j];
				//cout << "temp->letter.c: " << temp->letter.c << endl;
				present = true;
			}
		}
	}
	
	return present;
}

string BogValidator::to_upper(string s)
{
	int s_len = s.length();
	for (int i = 0; i < s_len; ++i){
		s[i] = toupper(s[i]);
	}
	return s;
}