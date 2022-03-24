/*
1671. Minimum Number of Removals to Make Mountain Array

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of 
elements to remove to make nums​​​ a mountain array.

 

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not 
need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at 
indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
 

Constraints:

3 <= nums.length <= 1000
1 <= nums[i] <= 109
It is guaranteed that you can make a mountain array out of nums.
*/

// complexity nlogn

class Solution {
public:
     int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int> t1, t2, t(n);
        int res=INT_MAX;
        for(int i=0; i<n; i++) {
            auto it=lower_bound(t1.begin(), t1.end(), arr[i]);
            if(it==t1.end())
                t1.push_back(arr[i]);
            else
                *it=arr[i];
            t[i]=t1.size();
        } 
        for(int i=n-1; i>=0; i--) {
            auto it=lower_bound(t2.begin(), t2.end(), arr[i]);
            if(it==t2.end())
                t2.push_back(arr[i]);
            else
                *it=arr[i];
            
            if(t[i]>1&&t2.size()>1)
                res=min(res, n-(t[i]+(int)t2.size()-1));      
        }
        return res;
    }
};