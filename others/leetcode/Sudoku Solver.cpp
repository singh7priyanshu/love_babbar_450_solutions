/*
Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.


*/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<short> R(10), C(10), S(10);
        
        for(int y = 0; y < 9; y++) 
            for(int x = 0; x < 9; x++) {
                int z = (y / 3) * 3 + x / 3;
                int v = (board[y][x] == '.') ? 0 : board[y][x] - '0';
                R[y] |= 1 << v;
                C[x] |= 1 << v;
                S[z] |= 1 << v;
            }
			
        try {
            solve(R, C, S, board, -1, -1);
        } catch (const char* c) {
            return;
        }
    }
    
    void solve(vector<short>& R, vector<short>& C, vector<short>& S, vector<vector<char>>& board, int x, int y) {
        x =            (x + 1) % 9;
        y = (x == 0) ? (y + 1) : y;
        
        if (y == 9) 
            throw "done";
        
        if (board[y][x] == '.') {
            int z = (y / 3) * 3 + x / 3;

            for(int i = 1; i < 10; i++) {
                if (((R[y] | C[x] | S[z]) & (1 << i)) != 0) 
                    continue;

                short x0 = C[x];
                short y0 = R[y];
                short z0 = S[z];

                R[y] |= 1 << i;
                C[x] |= 1 << i;
                S[z] |= 1 << i;
                board[y][x] = '0' + i;
                
                solve(R, C, S, board, x, y);

                C[x] = x0;
                R[y] = y0;
                S[z] = z0;
                board[y][x] = '.';
            }
        } else {
            solve(R, C, S, board, x, y);
        }
    }
};

