/*
Chocolate Distribution problem

Given an array A[ ] of positive integers of size N, where each value represents 
the number of chocolates in a packet. Each packet can have a variable number of chocolates. 
There are M students, the task is to distribute chocolate packets among M students such that :

1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of 
   chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.
Example 2:

Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between
maximum chocolates and minimum chocolates
is 4 - 2 = 2 by choosing following M packets :
{3, 2, 4}.
Your Task:
You don't need to take any input or print anything. Your task is to complete the 
function findMinDiff() which takes array A[ ], N and M as input parameters and returns 
the minimum possible difference between maximum number of chocolates given to a student 
and minimum number of chocolates given to a student.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109
1 ≤ M ≤ N

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long start = 0, end = 0;
        long long mind = LONG_LONG_MAX;
        for(long long i = 0;i+m-1<n;i++){
            long long diff = a[i+m-1]-a[i];
            if(mind>diff){
                mind = diff;
                start = i;
                end = i+m-1;
            }
        }
        return a[end]-a[start];
    }   
};

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>a;
        long long x;
        for(long long i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        long long m;
        cin>>m;
        Solution ob;
        cout<<ob.findMinDiff(a,n,m)<<endl;
    }
    return 0;
}