
/*

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

Input

The only input line contains a string of n characters.

Output

Print one integer: the length of the longest repetition.

Constraints
1≤n≤106
Example

Input:
ATTCGGGA

Output:
3

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main (){
	string s;
	cin>>s;
	int ans = 1, c=0;
	char l ='A';
	for(char d : s){
		if(d==l){
			++c;
			ans= max(c,ans);
		}
		else{
			l=d;
			c=1;
		}
	}
cout << ans;

}
