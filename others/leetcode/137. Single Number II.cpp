/*

137. Single Number II


Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>v(32,0);
        
        for(auto x:nums)
        {
            int x1=abs(x);
            int i=0;
            while(x1)
            {
                v[i++]+=x1%2;
                x1/=2;
            }
        }
        
        int ans=0,c=0;
        for(int i=0;i<32;i++)
              ans+=(v[i]%3)*pow(2,i);
      
        
        for(auto x:nums)
              if(x==ans)
                  c++;
        if(c==0||c==3)
            ans=ans*-1;
        
        return ans;
    }
};