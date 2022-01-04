
/*

Your task is to calculate the number of trailing zeros in the factorial n!.

For example, 20!=2432902008176640000 and it has 4 trailing zeros.

Input

The only input line has an integer n.

Output

Print the number of trailing zeros in n!.

Constraints
1≤n≤109
Example

Input:
20

Output:
4

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=5;i<=n;i*=5 ){
		ans+=n/i;
	}
	cout<<ans;
}
