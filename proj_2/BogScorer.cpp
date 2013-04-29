
#include <iostream>
#include "BogScorer.h"

using namespace std;

BogScorer::BogScorer()
{
	//constructor
	NOT_WORD_SCORE = 0;
	curr_score = 0;
	num_words = 0;
	
	MAX_BIN_1 = 4;
	BIN_1_SCORE = 1;
	
	MAX_BIN_2 = 5;
	BIN_2_SCORE = 2;
	
	MAX_BIN_3 = 6;
	BIN_3_SCORE = 3;
	
	MAX_BIN_4 = 7;
	BIN_4_SCORE = 5;
	
	MIN_BIN_5 = 8;
	BIN_5_SCORE = 11;
}

BogScorer::~BogScorer()
{
	//destructor
}

void BogScorer::compute_score()
{
	string temp;
	
	while (cin >> temp){
		if (temp == "NO"){
			cout << NOT_WORD_SCORE << " " << temp << " ";
			cin >> temp;
			cout << temp << endl;
		}else{
			cin >> temp;
			if ((int)temp.length() <= MAX_BIN_1){
				curr_score += BIN_1_SCORE;
				cout << BIN_1_SCORE << " OK " << temp << endl;
			}else if ((int)temp.length() <= MAX_BIN_2){
				curr_score += BIN_2_SCORE;
				cout << BIN_2_SCORE << " OK " << temp << endl;
			}else if ((int)temp.length() <= MAX_BIN_3){
				curr_score += BIN_3_SCORE;
				cout << BIN_3_SCORE << " OK " << temp << endl;
			}else if ((int)temp.length() <= MAX_BIN_4){
				curr_score += BIN_4_SCORE;
				cout << BIN_4_SCORE << " OK " << temp << endl;
			}else {
				curr_score += BIN_5_SCORE;
				cout << BIN_5_SCORE << " OK " << temp << endl;
			}
			++num_words;
		}
	}
	
	cout << num_words << " words " << curr_score << " points" << endl;
}