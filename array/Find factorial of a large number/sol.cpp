/*
Factorials of large numbers

Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.


Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)


Constraints:
1 ≤ N ≤ 1000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>number;
        number.push_back(1);
        for(int i = 2;i<=N;i++){
            multiply(i,number);
        }
        reverse(number.begin(),number.end());
        return number;
    }
    
    void multiply(int n, vector<int>&number){
        int carry = 0;
        for(int i = 0;i<number.size();i++){
            int num = n*number[i];
            number[i] = (char)((num+carry)%10);
            carry = (num+carry)/10;
        }
        while(carry){
            number.push_back(carry%10);
            carry /= 10;
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        vector<int>result = ob.factorial(N);
        for(int i = 0;i<result.size();i++){
            cout<<result[i];
        }
        cout<<endl;
    }
    return 0;
}