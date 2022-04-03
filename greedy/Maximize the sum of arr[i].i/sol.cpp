/*
Maximize the sum of arr[i]*i

Given an array A of N integers. Your task is to write 
a program to find the maximum value of ∑arr[i]*i, 
where i = 0, 1, 2,…., n – 1.
You are allowed to rearrange the elements of the array.

Note: Since output could be large, hence module 109+7 
and then print answer.

 

Example 1:

Input : Arr[] = {5, 3, 2, 4, 1}
Output : 40
Explanation:
If we arrange the array as 1 2 3 4 5 then 
we can see that the minimum index will multiply
with minimum number and maximum index will 
multiply with maximum number. 
So 1*0+2*1+3*2+4*3+5*4=0+2+6+12+20 = 40 mod(109+7) = 40

Example 2:

Input : Arr[] = {1, 2, 3}
Output : 8


Your Task:
This is a function problem. The input is already taken care of 
by the driver code. You only need to complete the function 
Maximize() that takes an array (arr), sizeOfArray (n), and 
return the maximum value of an array. The driver code takes 
care of the printing.

Expected Time Complexity: O(nlog(n)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 107
1 ≤ Ai ≤ N
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int Maximize(int a[],int n){
        sort(a, a+n);
        long long int mod = 1000000007;
        long long int product = 0;
        for(int i = 0;i<n;i++){
            product = (product + ((long long int)a[i] * (i))%mod)%mod;
        }
        return product%mod;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n]; 
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a, n)<<endl;
    }
    return 0;
}