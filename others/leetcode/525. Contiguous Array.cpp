/*
525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an 
equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp; //Define a Hashmap
        mp.insert({0,-1}); // Insert 0 in map as initially the sum is 0(Explained below)
        int c = 0, mx = 0; // Define a count and a max veriable
        for(int i = 0;i<nums.size();i++){
            nums[i] == 1 ? c++ : c--; // If ith value in nums array is 1 increment count by 1, if it's 0 decrement count by 1
			/*
			If we find out that the count already exists in the hash map if check if the current is greater than the last one 
			Therefore we insert 0 at the start so we can get the in the conditional statement if after decrementing we get another 0
			Eg  1  1  1  0  0  0  0  1
			    1  2  3  2  1  0 -1  0
			  0                0     0
			  Hence we get the max subarray as we insert 0 at -1 index
			*/ 
            if(mp.find(c)!=mp.end()) mx = max(mx,i-mp[c]);
            else mp.insert({c,i}); // Or else we will insert the count
        }
        return mx; //Finally return the maximum length of a contiguous subarray
    }
};

