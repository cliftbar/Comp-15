#ifndef BOARD
#define BOARD
#include "bog_structs.h"

using namespace std;

class Board
{
public:
	Board();
	~Board();
	void build_board();
	void print_board();
private:
	void read_board();
}
	