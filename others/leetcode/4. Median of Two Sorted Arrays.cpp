/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106


*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, m = nums1.size(), n = nums2.size(), m1 = 0, n1 = 0, in = 0;
        vector<int>v(m+n);
        while(n1<n && m1<m){
            if(nums1[m1]<=nums2[n1]){
                v[in++] = nums1[m1++];
            }
            else{
                v[in++] = nums2[n1++];
            }
        }
        for(i = m1;i<m;i++){
            v[in++] = nums1[i];
        }
        for(i=n1;i<n;i++){
            v[in++] = nums2[i];
        }
        double ans = 0;
        int a = (m+n)/2;
        if((m+n)%2 == 0){
            ans  = v[a]+v[a-1];
            ans /= 2;
        }else{
            ans = v[a];
        }
        return ans ;
    }
};