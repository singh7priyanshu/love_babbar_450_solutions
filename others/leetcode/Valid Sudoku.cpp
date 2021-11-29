/*
Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/



class Solution {
public:
    //function to check if number repeats in vector
	bool comparer(vector<char>& in){
        sort(in.begin(), in.end());
        if(adjacent_find(in.begin(), in.end()) != in.end()){
                return false;
            }
            
        else{
            return true;
        }
}


    bool isValidSudoku(vector<std::vector<char>>& board) {
        const unsigned char size = 9;
        unsigned char mut = 0;
        unsigned char cont = 0;
        vector<char> comparelines;
        vector<char> comparecols;
        vector<char> comparesquares;
        // loop that pushes line in comparelines
	    for(int i = 0; i != size; i++){
            for(int f = 0; f != size; f++){
                if(board[i][f] != '.'){
                    comparelines.push_back(board[i][f]);
                }
            }
            // loop that pushes columns in comparecols
		    for(int c = 0; c != size; c++){
                if(board[c][i] != '.'){
                    comparecols.push_back(board[c][i]);
                }
            }
        
            //loop that pushes 3x3 squares into comparesquares
		    for(int d = mut; d != mut + 3; d++){
                for(int c = cont; c != cont + 3; c++){
                    if(board[d][c] != '.'){
                        comparesquares.push_back(board[d][c]);

                    }
                }
            }

            // checking
		    if(comparer(comparelines) && comparer(comparecols) && comparer(comparesquares)){
                comparecols.clear();
                comparelines.clear();
                comparesquares.clear();
            }
            else{
                return false;
            }
        
            // math needed to compare 3x3 squares
		    cont += 3;
            if(i == 2 || i == 5 || i == 8){
                mut += 3;
                cont = 0;
            }
        
        }
    
        return true;
        
    }
};