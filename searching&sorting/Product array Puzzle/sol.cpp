/*
Product array Puzzle

Given an array nums[] of size n, construct a Product Array P (of same size n) such 
that P[i] is equal to the product of all the elements of nums except nums[i].

 

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Example 2:

Input:
n = 2
nums[] = {12,0}
Output:
0 12

Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() 
that takes array nums[] and n as input parameters and returns a list of n integers 
denoting the product array P. If the array has only one element the returned list 
should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
 

Constraints:
1 <= n <= 1000
0 <= numsi <= 200
Array may contain duplicates.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //location of memory for product array and intialise it by 1;
        vector<long long int>vec(n, 1ll);
        if(n==1)return vec;
        long long temp = 1ll;
        for(int i = 0;i<n;i++){
            vec[i]*=temp;
            temp*=nums[i];
        }
        temp = 1ll;
        for(int i = n-1;i>=0;i--){
            vec[i]*=temp;
            temp*=nums[i];
        }
        return vec;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long int>arr(n),vec(n);
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        vec = ob.productExceptSelf(arr, n);
        for(int i = 0;i<n;i++)cout<<vec[i]<<" ";
        cout<<endl;
    }
    return 0;
}