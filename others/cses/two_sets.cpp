/*

Your task is to divide the numbers 1,2,…,n into two sets of equal sum.

Input

The only input line contains an integer n.

Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

Constraints
1≤n≤106
Example 1

Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6

Example 2

Input:
6

Output:
NO


*/ 

	






#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;
	cin>>n;
	if(n*(n+1)/2%2){
		cout<<"NO"<<"\n";
		return 0;
	}

	vector<int>v1,v2;
	int j = 0;
	if(n%4)j=3;
	else j=4;
	for(int i=0;i<(n-1)/4;++i){
		v1.push_back(4*i+1+j);
		v1.push_back(4*i+4+j);
		v2.push_back(4*i+2+j);
		v2.push_back(4*i+3+j);
	}
	if(n%4){
		v1.push_back(1);
		v1.push_back(2);
		v2.push_back(3);
		//v2.push_back(2);
	}else{
		v1.push_back(1);
		v1.push_back(4);
		v2.push_back(3);
		v2.push_back(2);
	}
	cout<<"YES\n";
	cout<<v1.size()<<"\n";
	for(int i : v1){
		cout<<i<<" ";
	}
	cout<<"\n";
	cout<<v2.size()<<"\n";
	for(int i:v2){
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}