//Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth 
//smallest element in the given array. It is given that all array elements are distinct.
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//using priority queue - nlogn	
	//using sorting - nlogn
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		pq.push(a[i]);
		if ((int)pq.size() > k) {
			pq.pop();
		}
	}	
 	cout << pq.top();
	return 0;
}