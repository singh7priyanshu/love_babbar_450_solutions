/*
CHOCOLA –Chocolate

https://www.spoj.com/problems/CHOCOLA/

We are given a bar of chocolate composed of m*n square pieces. 
One should break the chocolate into single squares. 
Parts of the chocolate may be broken along the vertical and 
horizontal lines as indicated by the broken lines in the picture.

A single break of a part of the chocolate along a chosen 
vertical or horizontal line divides that part into two 
smaller ones. 

Each break of a part of the chocolate is charged a cost 
expressed by a positive integer. This cost does not depend 
on the size of the part that is being broken but only depends 
on the line the break goes along. Let us denote the costs of 
breaking along consecutive vertical lines with x1, x2, ..., xm-1 
and along horizontal lines with y1, y2, ..., yn-1.

The cost of breaking the whole bar into single squares is the sum 
of the successive breaks. One should compute the minimal cost of 
breaking the whole chocolate into single squares.


For example, if we break the chocolate presented in the picture 
first along the horizontal lines, and next each obtained part 
along vertical lines then the cost of that breaking will be 
y1+y2+y3+4*(x1+x2+x3+x4+x5).

Task
Write a program that for each test case:

Reads the numbers x1, x2, ..., xm-1 and y1, y2, ..., yn-1
Computes the minimal cost of breaking the whole chocolate into 
single squares, writes the result.
Input
One integer in the first line, stating the number of test cases, 
followed by a blank line. There will be not more than 20 tests.

For each test case, at the first line there are two positive 
integers m and n separated by a single space, 2 <= m,n <= 1000. 
In the successive m-1 lines there are numbers 
x1, x2, ..., xm-1, one per line, 1 <= xi <= 1000. 
In the successive n-1 lines there are numbers y1, y2, ..., yn-1, 
one per line, 1 <= yi <= 1000.

The test cases will be separated by a single blank line.

Output
For each test case : write one integer - the minimal cost of 
breaking the whole chocolate into single squares.

Example
Input:
1

6 4
2
1
3
1
4
4
1
2

Output:
42
*/

#include <bits/stdc++.h>
using namespace std;
 
#define min(a,b) (((a)<(b))?(a):(b))
typedef long long LL;
bool comp(LL a, LL b){ return a>b;}
 
LL x[1001],y[1001],dp[1001][1001];
 
int main() {
    LL i,j,m,n,t; cin>>t;
    while(t--){
        cin>>m>>n;
        m--;
        n--;
        for(i=1;i<=m;i++)cin>>x[i];
            //scanf("%lld",x+i);
        for(i=1;i<=n;i++)cin>>y[i];
            //scanf("%lld",y+i);
        sort(x+1,x+1+m,comp);
        sort(y+1,y+n+1,comp);
        dp[0][0] = 0;
        for(i=1;i<=m;i++) dp[i][0] = x[i] + dp[i-1][0];
        for(i=1;i<=n;i++) dp[0][i] = y[i] + dp[0][i-1];
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                LL t1 = dp[i-1][j] + x[i]*(j+1);
                LL t2 = dp[i][j-1] + y[j]*(i+1);
                dp[i][j] = min(t1,t2);
            }
        }
        printf("%lld\n",dp[m][n]);
    }
    return 0;
} 