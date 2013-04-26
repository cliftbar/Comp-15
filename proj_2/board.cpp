#include "board.h"

Board::Board()
{
	//constructor
}

void Board::build_board(int rows, int cols)
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
	
	
}

void Board::print_board()
{
	//print board function
	cout << "board is: " << endl;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << board[i][j].l.c << " ";
		}
		cout << endl;
	}
	
	return true;
}