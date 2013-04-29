
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
	said_cap = 2;
	said_array = new string[said_cap];
	num_said = 0;
}

BogValidator::~BogValidator()
{
	//destructor
}

bool BogValidator::readDict()
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

bool BogValidator::isValid(string s)
{
	bool in_dict = false;
	bool in_board = false;
	check_string = s;
	string rec_string = "";
	bool found_start = find_start_letter(s[0]);
	rec_string[0] = s[0];
	BogLettList* list_iter = word_list;
	
	in_dict = dict.isWord(s);
	
	//can be a big or function
	if (found_start && s.length() >= 3 && in_dict){
		while (list_iter != NULL){
			check_row = list_iter->letter.row;
			check_col = list_iter->letter.col;
			in_board = on_board(rec_string, 0,check_row, check_col);
			if (in_board){
				break;
			}
			list_iter = list_iter->next;
		}
	}else if (found_start && contains_q(s) && in_dict && s.length() >= 2){
		while (list_iter != NULL){
			check_row = list_iter->letter.row;
			check_col = list_iter->letter.col;
			in_board = on_board(rec_string, 0,check_row, check_col);
			if (in_board){
				break;
			}
			list_iter = list_iter->next;
		}
	}else{
		in_board = false;
	}
		
		
	while(word_list != NULL){
		list_iter = word_list;
		word_list = word_list->next;
		delete list_iter;
	}
	
	return (in_board && in_dict);
}

void BogValidator::checkWords()
{
	string curr_word;
	string temp = "";
	bool valid;
	bool said = false;
	bool q_no_u = false;
	
	while (cin >> curr_word){
		said = false;
		q_no_u = false;
		curr_word = to_upper(curr_word);
		
		for (int i = 0; i < (int)curr_word.length(); ++i){
			if (curr_word[i] == 'Q' && curr_word[i+1] != 'U'){
				cout << "NO " << curr_word << endl;
				q_no_u = true;
			} 
		}
		
		for (int i = 0; i < (int)curr_word.length(); ++i){
			if (curr_word[i] == 'Q' && curr_word[i+1] == 'U'){
				curr_word.erase(curr_word.begin() + i + 1);
			}
		}
		
		if (!q_no_u){
			valid = isValid(curr_word);
		
			for (int i = 0; i < (int)curr_word.length() + 1; ++i){
				if (curr_word[i] == 'Q'){
					curr_word.insert(curr_word.begin() + i + 1, 'U');
				}
			}
		
			if(num_said == 0){
				said_array[num_said] = curr_word;
				++num_said;
			}else{
				for (int i = 0; i < num_said; ++i){
					if (curr_word == said_array[i]){
						said = true;
					}
				}
				if(!said){
					said_array[num_said] = curr_word;
					++num_said;
				}
			}
		
			if (said_cap-1 <= num_said){
				expand_said();
			}
		
			if(valid && !said){
				cout << "OK " << curr_word << endl;
			}else {
				cout << "NO " << curr_word << endl;
			}
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
	
	if (board[c_row][c_col].visited){
		board[c_row][c_col].visited = false;
		return false;
	}else {
		board[c_row][c_col].visited = true;
	}
	
	if (s_in == check_string){
		board[c_row][c_col].visited = false;
		return true;
	}
	
	up = p_board_director(s_in, next_pos, row_up, c_col);//check up
	up_right = p_board_director(s_in, next_pos, row_up, col_right);
	//check up, right
	right = p_board_director(s_in, next_pos, c_row, col_right);//check right
	down_right = p_board_director(s_in, next_pos, row_down, col_right);
	//check down, right
	down = p_board_director(s_in, next_pos, row_down, c_col);//check down
	down_left = p_board_director(s_in, next_pos, row_down, col_left);
	//check down, left
	left = p_board_director(s_in, next_pos, c_row, col_left);//check left
	up_left = p_board_director(s_in, next_pos, row_up, col_left);
	//check up, left
	bool state = (true ==
		(up||up_right||right||down_right||down||down_left||left||up_left));
	board[c_row][c_col].visited = false;
	return state;
}

bool BogValidator::p_board_director(string curr_string, int n_pos, int  n_row,
		int n_col)
{
	if ((0 <= n_row && n_row < rows) && (0 <= n_col && n_col < cols)
	&& board[n_row][n_col].l.c == check_string[n_pos]){
		return on_board(curr_string, n_pos, n_row, n_col);
	}
	return false;
}

void BogValidator::build_board()
{
	board = new Letter*[rows];
	for (int i = 0; i < rows; ++i){
		board[i] = new Letter[cols];
	}
}

void BogValidator::print_board()
{
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << board[i][j].l.c << " ";
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
			if (board[i][j].l.c == c){
				if (word_list == NULL){
					word_list = new BogLettList;
					temp = word_list;
				}else {
					temp->next = new BogLettList;
					temp = temp->next;
				}
				temp->next = NULL;
				temp->letter = board[i][j].l;
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

void BogValidator::expand_said()
{
	string* temp = new string[said_cap*2];
	
	for (int i = 0; i < said_cap; ++i){
		temp[i] = said_array[i];
	}
	
	delete [] said_array;
	said_cap = said_cap * 2;
	
	said_array = temp;
}

bool BogValidator::contains_q(string str_in)
{
	bool is_q = false;
	
	for (int i = 0; i < (int)str_in.length(); ++i){
		if(str_in[i] == 'Q'){
			is_q = true;
		}
	}
	
	return is_q;
}