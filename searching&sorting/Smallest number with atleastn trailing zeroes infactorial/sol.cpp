/*
Smallest number with atleastn trailing zeroes infactorial

Given a number n. The task is to find the smallest number whose factorial 
contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, 
and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 104

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findNum(int n){
            if(n==1)return (5);
            int s = 0, e = 5*n;
            int ans = -1;
            while(s<=e){
                int mid = (s+e)/2;
                if(check(mid, n)){
                    ans = mid;
                    e = mid-1;
                }
                else s = mid+1;
            }
            return ans;
        }
        
        bool check(int mid, int n){
            int cnt = 0, f = 5;
            while(f<=mid){
                cnt += mid/f;
                f*=5;
            }
            return (cnt >= n);
        }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.findNum(n)<<endl;
    }
    return 0;
}


