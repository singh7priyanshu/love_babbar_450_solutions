
/*

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

On each move, you may increase the value of any element by one. What is the minimum number of moves required?

Input

The first input line contains an integer n: the size of the array.

Then, the second line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print the minimum number of moves.

Constraints
1≤n≤2⋅105
1≤xi≤109
Example

Input:
5
3 2 5 1 7

Output:
5

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;cin>>n;
	int mx=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		mx = max(x,mx);
		ans+=mx-x;
	}
	cout<< ans;
}