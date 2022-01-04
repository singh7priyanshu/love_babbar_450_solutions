

/*


A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:


            1  2  9  10 25
            4  3  8  11 24
            5  6  7  12 23
            16 15 14 13 22
            17 18 19 20 21


Your task is to find out the number in row y and column x.

Input

The first input line contains an integer t: the number of tests.

After this, there are t lines, each containing integers y and x.

Output

For each test, print the number in row y and column x.

Constraints
1≤t≤105
1≤y,x≤109
Example

Input:
3
2 3
1 1
4 2

Output:
8
1
15

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		ll y,x;
		cin>>y>>x;
		ll z= max(y,x);
		ll z2=(z-1)*(z-1);
		ll ans=0;
		if(z%2){
			if(y==z){
				ans = z2 +x;
			}
			else{
				ans = z2 +2*z-y;  
			}
		}
		else{
			if(x==z){
				ans = z2+y;
			}
			else{
				ans = z2+2*z-x;
			}
		}
		cout<<ans<<"\n";
	}
}