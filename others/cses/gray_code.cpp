
/*
A Gray code is a list of all 2n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

Your task is to create a Gray code for a given length n.

Input

The only input line has an integer n.

Output

Print 2n lines that describe the Gray code. You can print any valid solution.

Constraints
1≤n≤16
Example

Input:
2

Output:
00
01
11
10
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void generateGrayarr(int n){
	if(n<=0){
		return;
	}
	vector<string>arr;
	arr.push_back("0");
	arr.push_back("1");

	int i,j;
	for(i=2;i<(1<<n);i=i<<1){
		for(j=i-1;j>=0;j--){
			arr.push_back(arr[j]);
		}
		for(j=0;j<i;j++){
			arr[j] = "0"+arr[j];
		}
		for(j=i;j<2*i;j++){
			arr[j] = "1"+arr[j];
		}
	}
	for(i =0 ; i<arr.size();i++){
		cout<<arr[i]<<"\n";
	}
}

int main (){
	int n;
	cin>>n;
	generateGrayarr(n);
	return 0;
}