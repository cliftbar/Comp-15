struct BogLett {
	char c;
	int row, col;
};
struct BogWord {
	int numLetts;
	BogLett* letts;
};
struct BogWordList {
	int numWords;
	BogWord* words;
};
