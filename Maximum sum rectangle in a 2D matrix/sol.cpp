/*
Maximum sum rectangle in a 2D matrix

Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.

  1     4    -1     -4     -20
      ________________
 -8  | -3     4     2 |      1
     |                | 
  3  |  8    10     1 |      3
     |                | 
 -4  | -1     1     7 |     -6
     |________________|


Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the 
optimal choice.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function maximumSumRectangle() 
which takes the number R, C, and the 2D matrix M as input 
parameters and returns the maximum sum subarray.


Expected Time Complexity:O(R*R*C)
Expected Auxillary Space:O(R*C)
 

Constraints:
1<=R,C<=500
-1000<=M[i][j]<=1000


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Implementation of Kadane's algorithm for
    // 1D array. The function returns the maximum
    // sum and stores starting and ending indexes
    // of the maximum sum subarray at addresses
    // pointed by start and finish pointers
    // respectively.
    int kadane(int* arr, int* start, int* finish, int n) {
        // initialize sum, maxSum and
        int sum = 0, maxSum = INT_MIN, i;

        // Just some initial value to check
        // for all negative values case
        *finish = -1;

        // local variable
        int local_start = 0;

        for (i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum < 0) {
                sum = 0;
                local_start = i + 1;
            } else if (sum > maxSum) {
                maxSum = sum;
                *start = local_start;
                *finish = i;
            }
        }

        // There is at-least one
        // non-negative number
        if (*finish != -1) return maxSum;

        // Special Case: When all numbers
        // in arr[] are negative
        maxSum = arr[0];
        *start = *finish = 0;

        // Find the maximum element in array
        for (i = 1; i < n; i++) {
            if (arr[i] > maxSum) {
                maxSum = arr[i];
                *start = *finish = i;
            }
        }
        return maxSum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
        int left, right, i;
        int temp[R], sum, start, finish;
        for (left = 0; left < C; ++left) {
            memset(temp, 0, sizeof(temp));
            for (right = left; right < C; ++right) {
                for (i = 0; i < R; ++i) temp[i] += M[i][right];
                sum = kadane(temp, &start, &finish, R);
                if (sum > maxSum) {
                    maxSum = sum;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = start;
                    finalBottom = finish;
                }
            }
        }
        return maxSum;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>v (n, vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++) cin>>v[i][j]; 
        }
        Solution ob;
        cout<<ob.maximumSumRectangle(n, m, v)<<endl;
    }
}

/* 
leetcode

363. Max Sum of Rectangle No Larger Than K
https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

Given an m x n matrix matrix and an integer k, 
return the max sum of a rectangle in the matrix such 
that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

 

Example 1:

      ________
 1   | 0    1 |
     |        |
 0   |-2    3 |
     |________|

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle 
[[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105

*/

class Solution {
public:
    int maxSubarraySum(vector<int>& sum, int k, int row){
        int curSum= 0, curMax = INT_MIN;
        set<int>sumSet;
        sumSet.insert(0);
        for(int r = 0;r<row;r++){
            curSum += sum[r];
            auto it = sumSet.lower_bound(curSum - k);
            if(it != sumSet.end()){
                curMax = max(curMax, curSum - *it);
            }
            sumSet.insert(curSum);
        }
        return curMax;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ret = INT_MIN;
        for(int i = 0;i<col;i++){
            vector<int>sum(row, 0);
            for(int j = i;j<col;j++){
                for(int r = 0;r<row;r++){
                    sum[r] += matrix[r][j];
                }
                int cur_max = maxSubarraySum(sum, k, row);
                ret = max(ret, cur_max);
            }
        }
        return ret;
    }
};


/*
leetcode

85. Maximal Rectangle
https://leetcode.com/problems/maximal-rectangle/

Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],
                ["1","0","1","1","1"],
                ["1","1","1","1","1"],
                ["1","0","0","1","0"]]
Output: 6

Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

    /* Here the whole code for Max Area Histogram will be used. 
        And the logic is simple, just compress the 2D matrix into 
        1D array and call the MAH code. To compress the 2D matrix, do like this:
         1. copy the 1st row as it is in the 1D array.
         2. Now for the rest of the rows, make a new 1D array in such a manner 
         that, if the element at current index 'idx' is 1(>0) then store the 
         (prev_arr[idx] + 1) in the new array, otherwise leave it to zero. 
         Now pass this array in MAH and store the ans.
         3. Repeat step 2 for all the remaining rows and keep on 
         storing the max value of the area received from MAH.
    
            Note : 
            1. MAH stands for Maximum area Histogram.
            2. nsl : nearest smallest to left.
            3. nsr : nearest smallest to right.
    */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
         int ans = INT_MIN;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> mask(m,0);
        for(int j=0; j<m; j++) if(matrix[0][j] == '1') mask[j] = 1;
        ans = largestRectangleArea(mask);
        for(int i=1; i<n; i++) {
            vector<int> tmp(m,0);
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') tmp[j] = mask[j] + 1;
            }
            mask = tmp;   
            ans = max(ans, largestRectangleArea(mask));
        }
        return ans;
    }
private:
    void nsl(vector<int>& heights, vector<int>& left) {
        stack<pair<int,int>> st;
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && st.top().first >= heights[i]) st.pop();
            if(st.empty()) left.push_back(-1);
            else left.push_back(st.top().second);
            st.push({heights[i], i});
        }
    }
    
    void nsr(vector<int>& heights, vector<int>& right) {
        stack<pair<int,int>> st;
        for(int i=heights.size()-1; i>=0; i--) {
            while(!st.empty() && st.top().first >= heights[i]) st.pop();
            if(st.empty()) right.push_back(-1);
            else right.push_back(st.top().second);
            st.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        int n = heights.size();
        nsl(heights, left);
        nsr(heights, right);
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            int area=0,w=0,h=heights[i];
            w += (left[i] == -1) ? i+1 : i-left[i] ;
            w += (right[i] == -1) ? n-i-1 : right[i]-i-1;
            area = w*h;
            ans = max(ans, area);
        }
        return ans;
    }
};