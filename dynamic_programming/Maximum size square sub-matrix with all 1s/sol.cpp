/*
Maximum size square sub-matrix with all 1s

Given a binary matrix mat of size n * m, find out 
the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
Example 2:

Input: n = 2, m = 2
mat = {{0, 0}, 
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.

Your Task:

You do not need to read input or print anything. Your task is 
to complete the function maxSquare() which takes n, m and mat 
as input parameters and returns the size of the maximum square 
sub-matrix of given matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 50
0 ≤ mat[i][j] ≤ 1 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int sub[n][m], maxsize = 0;
        for(int i = 0;i < m;i++){
            sub[0][i] = mat[0][i];
            maxsize = max(maxsize, sub[0][i]);
        }
        for(int i = 0;i < n;i++){
            sub[i][0] = mat[i][0];
            maxsize = max(maxsize, sub[i][0]);
        }
        for(int i = 1;i < n;i++){
    		for(int j = 1;j < m;j++){
    			if(mat[i][j] == 1)
    				sub[i][j] = min(sub[i-1][j-1], min(sub[i][j-1], sub[i-1][j])) + 1;
    			else
    				sub[i][j]=0;
				maxsize = max(maxsize, sub[i][j]);
    		}
    	}
    	return maxsize;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>mat(n, vector<int>(m, 0));
        for(int i = 0;i<n*m;i++)cin>>mat[i/m][i%m];
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<endl;
    }
}
