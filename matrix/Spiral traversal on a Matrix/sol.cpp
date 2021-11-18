/*
Spirally traversing a matrix

Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.

Constraints:
1 <= r, c <= 100
0 <= matrixi <= 100

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int row = 0;
        int col = 0;
        vector<int> output;
        
        while(row<r && col<c)
        {
           //storing the elements of 1st row from the remaining rows, in a list.
           for(int i=col; i<c; i++)
               output.push_back(matrix[row][i]);
           row++;
           
           //storing elements of last column from remaining columns, in list.
           for(int i=row; i<r; i++)
               output.push_back(matrix[i][c-1]);
           c--;
           
           //storing the elements of last row from remaining rows, in a list.
            if(row<r)
            {
                for(int i=c-1; i>=col; --i)
                    output.push_back( matrix[r-1][i]);
                r--;
            }
           //storing elements of 1st column from the remaining columns, in list.
            if(col<c)
            {
                for(int i=r-1; i>=row; --i)
                    output.push_back( matrix[i][col]);
                col++;    
            }   
           
        }
        //returning the list.
        return output;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>>matrix(r);
        for(int i=0;i<r ;i++){
            matrix[i].assign(c,0);
            for(int j=0;j<c;j++){
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int>result =ob.spirallyTraverse(matrix,r,c);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}