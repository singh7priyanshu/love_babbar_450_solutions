/*
Palindromic Array

Given a Integer array A[] of n elements. Your task is to complete the function 
PalinArray. Which will return 1 if all the elements of the Array are palindrome 
otherwise it will return 0.


Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    //which is a palindrome number.
A[1] = 222   //which is a palindrome number.
A[2] = 333   //which is a palindrome number.
A[3] = 444  //which is a palindrome number.
A[4] = 555  //which is a palindrome number.
As all numbers are palindrome so This will return 1.

Constraints:
1 <=T<= 50
1 <=n<= 20
1 <=A[]<= 10000


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x){
        int copy = x;
        int rem = 0;
        int rev = 0;
        while(copy!=0){
            rem = copy%10;
            rev = rev*10+rem;
            copy/=10;
        }
        if(x!=rev)return false;
        return true;
    }
    int PalinArray(int a[], int n){
        for(int i = 0;i<n;i++){
            if(!isPalindrome(a[i]))return 0;
        }
        return 1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.PalinArray(a,n)<<endl;
    }
    return 0;
}

