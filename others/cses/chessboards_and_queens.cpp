
/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s[8];
	for(int i=0;i<8;++i){
		cin>>s[i];
	}
	int p[8],ans=0;
	iota(p,p+8,0);
	do{
		bool ok=1;
		for(int i=0;i<8;++i){
			ok&=s[i][p[i]]==".";
		}
		memset(b,0,15);
		for(int i=0;i<8;i++){
			if(b[i+p[i]]){
				ok=0;
			}
			b[i+p[i]]=1;
		}
		memset(b,0,15);
		for(int i=0;i<8;++i){
			if(b[i+7-p[i]]){
				ok=0;
			}
			b[i+7-p[i]]=1;
		}
		ans+=ok;
	}while(next_permutation(p,p+8));
	cout<<ans;
}
*/


  
/*
Problem Name: Chessboard and Queens
Problem Link: https://cses.fi/problemset/task/1624
Author: Sachin Srivastava (mrsac7)
*/


#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a;i<b;i++)
char chess[8][8];
int c=0;
bool ld[15], rd[15], row[7];
void rec(int j){
	if (j==8) {c++; return;}
	rep(i,0,8){
		if (chess[i][j]=='.' && ld[i-j+7]==0 && rd[i+j]==0 && row[i]==0){
			ld[i-j+7]=1, rd[i+j]=1, row[i]=1;
			rec(j+1);
			ld[i-j+7]=0, rd[i+j]=0, row[i]=0;
		}
	}
}
int main(){
	rep(i,0,8)rep(j,0,8)cin>>chess[i][j];
	rec(0);
	cout<<c;
}
