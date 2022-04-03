/*
410. Split Array Largest Sum

Given an array nums which consists of 
non-negative integers and an integer m, you 
can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum 
among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)

*/

class Solution {
public:
    bool check(vector<int>& nums, int m, int curr){
        int i=-1, n = nums.size(), count=1;
        
        int sum=0;
        
        while(++i<n && count<=m){
		//if adding the nums[i] does not make the sum greater than curr (mid), we add it to group
            if(sum+nums[i] <= curr) sum += nums[i];  
		// else we can add a new group to store the remaining element.
            else sum=nums[i], count++;
        }
		
		//If the total number of groups is less than the m, we can split the any of the current group of size >=2.
		//this will not increase the maximum sum and hence our answer will still be valid
		
        return count<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int e=0,s=0,mid,ans;
        for(auto x : nums){
			e += x;               //e stores the sum of the nums, upper range of Binary Search
			s=max(s,x);          //s stores the largest element in array nums, lower range of Binary Search
		}	
        ans = e; 
        
        while(s<=e){
            mid = s + (e-s)/2;
            
            if(check(nums,m,mid)){
                ans = min(ans,mid);
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};