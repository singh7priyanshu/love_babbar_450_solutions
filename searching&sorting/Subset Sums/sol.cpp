/*
Subset Sums

/*
SUBSUMS - Subset Sums
#binary-search #bitmasks

Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN 
(-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S 
(including the empty one) have a sum between A and B 
(-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

Input
The first line of standard input contains the three integers N, A, and B. 
The following N lines contain S1 through SN, in order.

Output
Print a single integer to standard output representing the number of subsets 
satisfying the above property. Note that the answer may overflow a 32-bit integer.

Example
Input:
3 -1 2
1
-2
3

Output:
5
The following 5 subsets have a sum between -1 and 2:

0 = 0 (the empty subset)
1 = 1
1 + (-2) = -1
-2 + 3 = 1
1 + (-2) + 3 = 2

*/

#include<bits/stdc++.h>
using namespace std;
void subset(int s[],vector<int> &v,int n,int start)
{
    int i, j, sum;
    for(i = 0; i < pow(2,n); i++) {
        sum = 0;
        for(j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum = sum + s[j+start];
            }
        }
        v.push_back(sum);
    }
}
int main()
{
    int n, a, b, i, j, s[40], hi, lo;
    vector<int> left,right;
    long long int sum;
    sum = 0;
    scanf("%d%d%d",&n,&a,&b);

    for(i = 0;i < n; i++) {
        scanf("%d",&s[i]);
    }

    subset(s,left,n/2,0);
    subset(s,right,(n&1)?n/2+1:n/2,n/2);

    sort(right.begin(),right.end());

    for(i = 0; i < left.size();i++) {
        lo = lower_bound(right.begin(),right.end(),a-left[i])-right.begin();
        hi = upper_bound(right.begin(),right.end(),b-left[i])-right.begin();
        sum = sum + (hi-lo);
    }
    printf("%lld\n",sum);
}
