/*
Bishu and Soldiers

Bishu went to fight for Coding Club. There were N soldiers with various powers. 
There will be Q rounds to fight and in each round, Bishu's power will be varied. 
With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). 
After each round, All the soldiers who are dead in the previous round will reborn. 
Such that in each round there will be N soldiers to fight. As Bishu is weak 
in mathematics, help him to count the number of soldiers that he can kill in 
each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.
The second line contains an array of N numbers denoting the power of each soldier
This third line contains Q, which denotes the number of rounds.
Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:

For each round, the output should be an array of two numbers. 
The first number should be the number of soldiers that Bishu can beat, 
and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.

CONSTRAINTS:

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100

Sample Input
7
1 2 3 4 5 6 7
3
3
10
2
Sample Output
3 6
7 28
2 3
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
There are 7 soldiers, each with the indicated power.

There are 3 rounds.

In the first round, Bishu's power is 3, which is greater than 3 soldiers, with 
the cumulative power of 6. Hence, the answer is 3 6

Similarly for the next round.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define xag ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int p; int q;cin>>q;
    while(q--){
        int cs=0;
        cin>>p;
        int x=upper_bound(a,a+n,p)-a;
        for(int i=0;i<x;i++)cs+=a[i];
        cout<<x<<" "<<cs<<endl;
    }
    return 0;
}

/*
mechanism of upper_bound function.
Vector contains : 10 20 30 40 50
upper_bound for element 35(here as p) is at position : 3
upper_bound for element 45(here as p) is at position : 4
*/