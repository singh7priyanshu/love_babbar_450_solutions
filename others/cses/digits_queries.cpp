
/*
Consider an infinite string that consists of all positive integers in increasing order:

12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?

Input

The first input line has an integer q: the number of queries.

After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.

Output

For each query, print the corresponding digit.

Constraints
1≤q≤1000
1≤k≤1018
Example

Input:
3
7
19
12

Output:
7
4
1
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MaxN = 1e5;
const ll mod = 1e9 + 7;
 
ll fun(ll x, ll size) {
	ll count = 0;
	for(int i = 1; i < size; i++) {
		ll num = (9ll * pow(10, i-1));
		count += (num * i);
	}
	ll mi = pow(10ll, size - 1);
	count += ((x - mi) * size) + 1;
	return count;
	// returns starting index of x.
}


int main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
  		ll N;
		cin >> N;
		ll sum = 0, which_size;
 
		for(int i = 1; i <= 18; i++) {
			ll num = (9ll * pow(10, i-1));
			sum += (num * i);
			if(N <= sum) {
				which_size = i;
				break;
			}
		}
 
		ll lo = pow(10ll, which_size - 1);
		ll hi = pow(10ll, which_size) - 1;
 
		// cout << "lo : " << lo << " hi : " << hi << endl;
		ll mid, ans = 0, index = 0;
 
		while(lo <= hi) {
			mid = (lo + hi)/2;
			ll value = fun(mid, which_size);
			if(value <= N) {
				index = max(index, value);
				ans = max(ans, mid);
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
 
		// cout << ans << " " << index << "\n";
 
		string str = to_string(ans);
 
		for(auto ch : str) {
			if(N == index) {
				cout << (ch - '0')  << "\n";
				break;
			}
			index++;
		}
 
	}
 
}
