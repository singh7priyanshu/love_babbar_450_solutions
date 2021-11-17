/*
3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
 

Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min=20000; // choose any big number greater than 10K(constraint)
		int csum;     // csum stores sum of triplet with minimum diff
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int l,r;
            l=i+1;
            r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int dif=abs(sum-target);      // stores diffrance of sum and target 
                
                if(dif<min){
                    min=dif;
                    csum=sum;
                }
                if(sum>target) r--;
                else if(sum<target) l++;
                else return sum;   // if sum and target are same then it is the closet so no need to check further
            }
        }
        return csum;
    }
};
