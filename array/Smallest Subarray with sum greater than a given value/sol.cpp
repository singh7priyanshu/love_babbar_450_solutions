/*
Smallest Subarray with sum greater than a given value

209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the 
minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the 
sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
       int p1=0,p2=0,ans =INT_MAX; 
       int n = nums.size();  
       int sum = 0;
       
       while(p2<n) // p1 and p2 is a pointer which keep track of cumulative sum >= target
       {  
           sum+= nums[p2];
        
           if(sum >= target)
           {
               while(sum>=target)          //subtract those values from cumulative sum till it becomes less than target
               {
                   sum -= nums[p1];
                   p1++;
               }
               
               ans = min(ans,(p2-p1+1)+1); //calculate the length of array 

               //(p2-p1+1) is the length of array which has 1 element so that sum >= target
               //(p2-p1+1)+1 include the missing element length into your array
           }
             p2++;
           
       }
        
       return ans == INT_MAX ? 0 : ans; 
        
        
    }
};