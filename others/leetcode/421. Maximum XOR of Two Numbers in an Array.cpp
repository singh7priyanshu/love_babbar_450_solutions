/*
421. Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], 
where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1

*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxAns = 0 ;
    

        for(int i = 31 ; i >= 0 ; i--) {
            maxAns = maxAns << 1;
            set <int> s;
            
            for(int j = 0 ;  j < nums.size() ; j++) {
			// take i bits from msb
                s.insert((nums[j] >> i));
            }
            // try to append all 1s to ans only then max will be there
            int newAns = maxAns | 1;
            
            for(int j : s) {
                
				// is xor of newAns with currelement present in set then only i can achieve the curr xor as 1 * 0 = 1 and 0 ^ 1  =1
                if(s.count(j ^ newAns)) {
                    maxAns = newAns;
                    break;
                }
            }
        }
        
        
        return maxAns;
    }
};