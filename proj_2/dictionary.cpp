//dictionary.cpp

#include "dictionary.h"
#include "node.h"
#include <iostream>
using namespace std;

/////////////////////////////Public Methods///////////////////////////////////

//constructor
Dictionary::Dictionary()
{
	s_curr = "";
	curr_s_pos = 0;
	root = NULL;
}

bool Dictionary::insert(string s)
{
	//cout << "word in: " << s << endl;//DEBUG CODE
	s_curr = clean_word(s);
	//cout << "word cleaned: " << s_curr << endl;//DEBUG CODE
	
	if(root == NULL){
		root = new Node;
	}
	
	rec_insert(root);
	
	return true;
}

bool Dictionary::isPrefix(string s)
{
	s_curr = clean_word(s);
	return rec_string_find(root, true);
}

bool Dictionary::isWord(string s)
{
	s_curr = clean_word(s);
	return rec_string_find(root, false);
}

void Dictionary::print_all_words()
{
	string print_string = "";
	rec_print(root, print_string);
}


///////////////////////////Private Methods////////////////////////////////////

string Dictionary::clean_word(string s_in)
{
	string r_string = "";
	
	for (unsigned int i = 0; i < s_in.length(); ++i){
		if (isalpha(s_in[i])){
			r_string += tolower(s_in[i]);
		}
	}
	
	return r_string;
}

int Dictionary::alpharray_pos(char c_in)
{
	return (c_in - 'a');
}

void Dictionary::rec_insert(Node* np_in)
{
	int curr_elm = alpharray_pos(s_curr[curr_s_pos]);
	//cout << "curr_s_pos: " << curr_s_pos << endl;//DEBUG CODE
	//cout << "s_curr.length(): " << s_curr.length() << endl;//DEBUG CODE
	//cout << "s_curr: " << s_curr << endl;//DEBUG CODE
	//cout << "curr_elm: " << curr_elm << endl;//DEBUG CODE
	
	if(curr_s_pos >= s_curr.length()){
		//cout << "check1" << endl;//DEBUG CODE
		np_in->set_word_here(true);
		curr_s_pos = 0;
		return;
	}else if(np_in->alpharray[curr_elm] == NULL){
		//cout << "check2" << endl;//DEBUG CODE
		np_in->alpharray[curr_elm] = new Node;
		if (np_in->alpharray[curr_elm] != NULL){
			++curr_s_pos;
			rec_insert(np_in->alpharray[curr_elm]);
			return;
		}else {
			cerr << "ERROR: Out of memory.  Program exit" << endl;
			exit(1);
		}
	}else if(np_in->alpharray[curr_elm] != NULL){
		//cout << "check3" << endl;//DEBUG CODE
		++curr_s_pos;
		rec_insert(np_in->alpharray[curr_elm]);
		return;
	}
}

bool Dictionary::rec_string_find(Node* np_in, bool prefix)
{
	int curr_elm = alpharray_pos(s_curr[curr_s_pos]);
	//cout << "curr_s_pos: " << curr_s_pos << endl;//DEBUG CODE
	//cout << "s_curr.length(): " << s_curr.length() << endl;//DEBUG CODE
	//cout << "s_curr: " << s_curr << endl;//DEBUG CODE
	//cout << "curr_elm: " << curr_elm << endl;//DEBUG CODE
	
	if(curr_s_pos >= s_curr.length()){
		if (prefix){
			curr_s_pos =0;
			//cout << "check5" << endl;//DEBUG CODE
			return true;
		}else {
			if (np_in->word_here()){
				//cout << "check6" << endl;//DEBUG CODE
				curr_s_pos =0;
				return true;
			}else {
				//cout << "check7" << endl;//DEBUG CODE
				curr_s_pos =0;
				return false;
			}
		}
	}else if(np_in->alpharray[curr_elm] == NULL){
		//cout << "check8" << endl;//DEBUG CODE
		curr_s_pos = 0;
		return false;
	}else {
		//cout << "check9" << endl;//DEBUG CODE
		++curr_s_pos;
		return rec_string_find(np_in->alpharray[curr_elm], prefix);
	}
}

void Dictionary::rec_print(Node* np_in, string print_string)
{
	string curr_path = print_string;
	if (np_in->word_here()){
		cout << print_string << endl;
	}
	
	for (int i =0; i < 26; ++i){
		print_string = curr_path;
		if (np_in->alpharray[i] != NULL){
			//cout << "check4" << endl;//DEBUG CODE
			print_string += (i + 'a');
			rec_print(np_in->alpharray[i], print_string);
		}else if (np_in->alpharray == NULL){
			return;
		}
	}
}



















