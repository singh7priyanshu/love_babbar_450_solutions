
/*

You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

Input

The first input line contains an integer n.

The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).

Output

Print the missing number.

Constraints
2≤n≤2⋅105
Example

Input:
5
2 3 1 5

Output:
4

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;cin>>n;
	ll sum=0;
	for(int i=0;i<n-1;i++){
		int temp;
		cin>>temp; 
		sum+=temp;
	}
	cout<<n*(n+1)/2 - sum;
}