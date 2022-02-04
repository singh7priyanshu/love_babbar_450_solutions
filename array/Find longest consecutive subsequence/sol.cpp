/*
Find longest coinsecutive subsequence

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N){
        unordered_set<int>S;
        int ans = 0;
        for(int i = 0;i<N;i++){
            S.insert(arr[i]);
        }
        for(int i = 0;i<N;i++){
            if(S.find(arr[i] - 1)==S.end()){
                int j = arr[i];
                while(S.find(j) != S.end())j++;
                ans = max(ans, j-arr[i]);
            }
        }
        return ans;
    }
};

int main(){
    int t,n,i,a[100001];
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.findLongestConseqSubseq(a, n)<<endl;
    }
    return 0;
}