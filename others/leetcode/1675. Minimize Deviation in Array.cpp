/*
1675. Minimize Deviation in Array

You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, 
and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, 
and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation 
will be 3 - 2 = 1.
Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation 
will be 5 - 2 = 3.
Example 3:

Input: nums = [2,10,8]
Output: 3
 

Constraints:

n == nums.length
2 <= n <= 105
1 <= nums[i] <= 109

*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;
        
        // Increasing all elements to as maximum as it can and tranck the minimum,
        // number and also the resutl
        for(int i = 0; i<n; ++i)
        {
            if((nums[i]%2) != 0)    // multiplication by 2 if nums[i] is odd
                nums[i] *= 2;   // maximising all odd numbers

        
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
        }
        
        int min_deviation = mx - mn;
        
        priority_queue<int> pq;
        // Inserting into Priority queue (Max Heap) and try to decrease as much we can
        for(int i = 0; i<n; ++i)
        {
            pq.push(nums[i]);
        }
        
        while((pq.top()) % 2 == 0)
        {
            int top = pq.top();
            pq.pop(); // popped the top element
            
            min_deviation = min(min_deviation, top - mn);
            top /= 2;
            mn = min(mn, top);  // updating min
            pq.push(top);   // pushing again the top as we have to minimize the max
        }
        
        min_deviation = min(min_deviation, pq.top() - mn);
        
        // we are returning mx - mn
        
        return min_deviation;
    }
};
