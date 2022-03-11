/*
Maximum Sum Increasing Subsequence

Given an array of n positive integers. Find the sum of the 
maximum sum subsequence of the given array such that the 
integers in the subsequence are sorted in increasing order 
i.e. increasing subsequence. 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the 
function maxSumIS() which takes N and array arr as input 
parameters and returns the maximum value.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int maxSumIS(int arr[], int n)  {  
	    int i, j, max = 0, a[n];
	    for( i = 0;i<n;i++)a[i] = arr[i];
	    for( i = 1;i<n;i++){
	        for( j = 0;j<i;j++){
	            if(arr[i] > arr[j] && a[i] < (a[j]+arr[i]))a[i] = a[j]+arr[i];
	        }
	    }
	    for( i = 0;i<n;i++){
	        if(max<a[i])max = a[i];
	    }
	    return max;
	}  
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.maxSumIS(a, n)<<endl;
    }
    return 0;
}

