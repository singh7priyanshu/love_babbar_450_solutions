/*
First Missing Positive

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0 && nums[i]<nums.size() && nums[i]!=i+1)
            {
                if(nums[nums[i]-1]==nums[i])
                    break;
                int temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
            }
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i+1)
                return i+1;
        return nums.back()+1;
    
    }
};


//or

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // we convert all the numbers except 1to n into n+1 as they won't give potential answer.
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]<=0){
                nums[i] = n+1;
            }
        }
        for(int i=0; i<n;i++){
            int temp = abs(nums[i]);
            //if there is any number in ranger 1to n , its index in 0 based array will get marked negative. 
            if(temp<n+1){
                nums[temp-1] = -abs(nums[temp-1]);
            }
        }
        for(int i=0;i<n;i++){
            // the first positive index+1 will give us result(if there was any element in array was not present
            //in the range of 1ton, otherwise we return n+1)
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    
    }
};
