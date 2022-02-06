/*
Find median in a row wise sorted matrix

Given a row wise sorted matrix of size RxC where R and C are always odd, 
find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() 
which takes the integers R and C along with the 2D matrix as input parameters and returns the 
median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1<= R,C <=150
1<= matrix[i][j] <=2000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < r; i++){
            if (matrix[i][0] < min)min = matrix[i][0];
            if (matrix[i][c-1] > max)max = matrix[i][c-1];
        }
        int desired = (r * c + 1) / 2;
        while (min < max){
            int mid = min + (max - min) / 2;
            int place = 0;
            for (int i = 0; i < r; ++i)place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (place < desired)min = mid + 1;
            else max = mid;
        }
        return min;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        vector<vector<int>>matrix(r, vector<int>(c));
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++)cin>>matrix[i][j];
        }
        Solution ob;
        cout<<ob.median(matrix, r, c)<<endl;
    }
    return 0;
}