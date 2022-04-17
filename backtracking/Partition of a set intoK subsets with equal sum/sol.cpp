/*
Partition of a set intoK subsets with equal sum

Given an integer array a[ ] of N elements and an 
integer K, the task is to check if the array a[ ] 
could be divided into K non-empty subsets with 
equal sum of elements.
Note: All elements of this array should be part of
exactly one partition.

Example 1:

Input: 
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
Explanation: we can divide above array 
into 3 parts with equal sum as (2, 4), 
(1, 5), (6)

Example 2:

Input: 
N = 5 
a[] = {2,1,5,5,6}
K = 3
Output: 
0
Explanation: It is not possible to divide
above array into 3 parts with equal sum.
Your Task:
You don't need to read input or print anything. Your 
task is to complete the function isKPartitionPossible() 
which takes the array a[], the size of the array N, and 
the value of K as inputs and returns true(same as 1) if 
possible, otherwise false(same as 0).

Expected Time Complexity: O(N*2N).
Expected Auxiliary Space: O(2N).

Constraints:
1 ≤ K ≤ N ≤ 10
1 ≤ a[i] ≤ 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int dp[(1<<16)+2];
    bool isKPartitionPossible(int nums[], int n, int k){
        int sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
            
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue; 
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) { 
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;  
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        int k; cin>>k;
        Solution ob;
        cout<<ob.isKPartitionPossible(a, n, k)<<endl;
    }
}

/*
We can also use fill to fill values in an array.


// C++ program to demonstrate working of fill()
#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    int arr[10];
  
    // calling fill to initialize values in the
    // range to 4
    fill(arr, arr + 10, 4);
  
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
  
    return 0;
}
Output:
4 4 4 4 4 4 4 4 4 4
*/