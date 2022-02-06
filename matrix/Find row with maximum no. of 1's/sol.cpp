/*
Find row with maximum no. of 1's

Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based 
index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function 
rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters 
and returns the 0-based index of the first row that has the most number of 1s. If no 
such row exists, return -1.
 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 103
0 ≤ Arr[i][j] ≤ 1 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int r = 0;
	    int c = m-1;
	    int max_row_index = -1;
	    while(r<n && c>=0){
	        if(arr[r][c] == 1){
	            max_row_index = r;
	            c--;
	        }
	        else r++;
	    }
	    return max_row_index;
	}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>arr(n, vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)cin>>arr[i][j];
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout<<ans<<endl;
    }
    return 0;
}