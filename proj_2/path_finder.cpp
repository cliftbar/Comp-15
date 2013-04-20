//path_finder.cpp

Path_Finder::Path_Finder(Dictionary &word_list)
{
	string curr_string = "";
	string* words_found = 


string* Path_Finder::string_walk(int i, int j)
{
	curr_string += board[i][j];
	
	if (dictionary.isWord()){
		//add to list of found words 
	}
	
	if (dictionary.isPrefix()){
		if (/*in board boundaries*/){
			string_walk((i+1),j);
			string_walk(i,(j+1));
			string_walk((i+1),(j+1));
		}
	}
	
	return;
}

