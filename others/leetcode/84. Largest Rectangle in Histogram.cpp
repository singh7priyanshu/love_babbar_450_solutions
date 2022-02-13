/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, return the area of the largest rectangle in the histogram.

       _                _  
     _| |             _|_|
    | | |     -->    |   |
    | | |  _         |   |  _
 _  | | |_| |     _  | 10|_| |
| |_| | | | |    | |_|   | | |
|2|1|5|6|2|3|    |2|1|   |2|3|

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),ans = 0, left[n], right[n];
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
            if(st.empty())left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};