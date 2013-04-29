//BogScorer.h

#ifndef BOGSCORER
#define BOGSCORER
#include "Dictionary.h"
#include "bog_structs.h"

class BogScorer
{
public:
	BogScorer();
	~BogScorer();
	void compute_score();
	
private:
	//string* output_array;
	int curr_score;
	int num_words;
	int NOT_WORD_SCORE;
	
	int MAX_BIN_1;
	int BIN_1_SCORE;
	
	int MAX_BIN_2;
	int BIN_2_SCORE;
	
	int MAX_BIN_3;
	int BIN_3_SCORE;
	
	int MAX_BIN_4;
	int BIN_4_SCORE;
	
	int MIN_BIN_5;
	int BIN_5_SCORE;
};

#endif