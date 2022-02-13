/*
Find next greater number with same set of digits. [Very Very IMP]

Implement the next permutation, which rearranges the list of numbers into Lexicographically 
next greater permutation of list of numbers. If such arrangement is not possible, it must be 
rearranged to the lowest possible order i.e. sorted in an ascending order. 
You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.
Example 2:

Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last 
permutation. So, the next permutation 
is the lowest one.
Your Task:
You do not need to read input or print anything. Your task is to complete the 
function nextPermutation() which takes N and arr[ ] as input parameters and returns
a list of numbers containing the next permutation.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind = 0;
        vector<int>v = arr;
        for(int i = N-2;i>=0;i--){
            if(v[i]<v[i+1]){
                ind = i;
                break;
            }
        }
        for(int i = N-1;i>ind;i--){
            if(v[i]>v[ind]){
                swap(v[i], v[ind]);
                ind++;
                break;
            }
        }
        for(int i = 0;i<(N-ind)/2;i++)swap(v[i+ind], v[N-i-1]);
        return v;
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>arr(N);
        for(int i = 0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans = ob.nextPermutation(N, arr);
        for(int u:ans)cout<<u<<" ";
        cout<<endl;  
    }
    return 0;
}