//path_finder.cpp

BogSolver::BogSolver(Dictionary &word_list)
{
	string curr_string = "";
	/*typedef*/ words_found = 
}

void BogSolver::solve()
{
	//loop for every element as a start position
	//rec_solve(i, j, char at [i][j])
	
	//if word_list == NULL, return false
	//else, return true


void BogSolver::rec_solve(int c_row, int c_col, string curr_string)
{
	int row_up = c_row - 1;
	int row_down = c_row + 1;
	int col_left = c_col -1;
	int col_right = c_col + 1;
 
	//set element to visited
		
	if (dictionary.isWord(curr_string)){
		//add to list of found words if in dictionary 
	}
	
	//Propogate in all directions where
	//Sample direction
	if(/*check if in bounds*/){
		if (isPrefix(curr_string + /*char @ next position*/){
			//travel to position, recursive call
			//rec_solve(proper row, proper col, curr_string + next char)
		}
	}
	/*for all directions, same construction
	 * if{
	 * }
	 */
	
	//if we get to the end of the function, no further prefixes
	//set element to unvisited
	//return
}

