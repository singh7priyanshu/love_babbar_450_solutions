/*
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105


*/


class Solution {
public:
    int trap(vector<int>height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        int maxWater = 0;
        for(int i=0;i<height.size();i++)
        {
            leftMax[i] = maxLeft; 
            if(maxLeft<=height[i]) maxLeft = height[i];
        }
        
        for(int i=height.size()-1;i>=0;i--)
        {
            rightMax[i] = maxRight;
            if(maxRight<=height[i]) maxRight = height[i];
        }
        
        for(int i=1;i<height.size()-1;i++)
        {
            int level = min(leftMax[i],rightMax[i]);
            if(level>height[i]) {
            maxWater+=level-height[i];
            }
        }
        
        return maxWater;
    }
};