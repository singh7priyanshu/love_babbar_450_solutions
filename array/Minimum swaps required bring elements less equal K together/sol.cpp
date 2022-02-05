/*
Minimum swaps required bring elements less equal K together

Given an array arr of n positive integers and a number k. One can apply a swap operation on the 
array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . 
Find the minimum number of swaps required to bring all the numbers less than or equal to k 
together, i.e. make them a contiguous subarray.

Example 1:

Input : 
arr[ ] = {2, 1, 5, 6, 3} 
K = 3
Output : 
1
Explanation:
To bring elements 2, 1, 3 together,
swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be- 
arr[] = {2, 1, 3, 6, 5}

Example 2:

Input : 
arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
K = 6 
Output :  
2 
Explanation: 
To bring elements 2, 5, 4 together, 
swap index 0 with 2 (0-based indexing)
and index 4 with 6 (0-based indexing)
such that final array will be- 
arr[] = {9, 7, 2, 5, 4, 7, 8}
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. 
You only need to complete the function minSwap() that takes an array (arr), sizeOfArray (n), 
an integer K, and return the minimum swaps required. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ N ≤ 105
1 ≤ Arri, K ≤107

*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minSwap(int arr[], int n, int k){
        int count = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] <= k)count++;
        }
        int bad = 0;
        for(int i = 0;i<count;i++){
            if(arr[i]>k)bad++;
        }
        int ans = bad;
        for(int i = 0, j = count; j<n; i++,j++){
            if(arr[i]>k)--bad;
            if(arr[j]>k)++bad;
            ans = min(ans,bad);
        }
        return ans;
    }
};

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        cin>>k;
        Solution ob;
        cout<<ob.minSwap(arr, n, k)<<endl;
    }
    return 0;
}