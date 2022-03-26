/*
Water Connection Problem

There are n houses and p water pipes in Geek Colony. 
Every house has at most one pipe going into it and at 
most one pipe going out of it. 

Geek needs to install pairs of tanks and taps in the 
colony according to the following guidelines.  

1. Every house with one outgoing pipe but no incoming 
    pipe gets a tank on its roof.
2. Every house with only one incoming and no outgoing 
    pipe gets a tap.

The Geek council has proposed a network of pipes where 
connections are denoted by three input values: ai, bi, di 
denoting the pipe of diameter di from house ai to house bi.

Find a more efficient way for the construction of this network 
of pipes. Minimize the diameter of pipes wherever possible.

Note: The generated output will have the following format. 
The first line will contain t, denoting the total number of 
pairs of tanks and taps installed. The next t lines contain 
three integers each: house number of tank, house number of tap, 
and the minimum diameter of pipe between them.


Example 1:

Input:
n = 9, p = 6
a[] = {7,5,4,2,9,3}
b[] = {4,9,6,8,7,1}
d[] = {98,72,10,22,17,66} 
Output: 
3
2 8 22
3 1 66
5 6 10
Explanation:
Connected components are 
3->1, 5->9->7->4->6 and 2->8.
Therefore, our answer is 3 
followed by 2 8 22, 3 1 66, 5 6 10.
 

Your Task:
You don't need to read input or print anything. Your task 
is to complete the function solve() which takes an integer 
n(the number of houses), p(the number of pipes),
the array a[] , b[] and d[] (where d[i] denoting the 
diameter of the ith pipe from the house a[i] to house b[i]) 
as input parameter and returns the array of pairs of tanks 
and taps installed i.e ith element of the array contains 
three integers: house number of tank, house number of tap 
and the minimum diameter of pipe between them.  

 

Expected Time Complexity: O(n+p)
Expected Auxiliary Space: O(n+p)

 

Constraints:
1<=n<=20
1<=p<=50
1<=a[i],b[i]<=20
1<=d[i]<=100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int n, p;
    vector<int> rd;
    vector<int> wt;
    vector<int> cd;
    int ans;
    int dfs(int w){
        if (cd[w] == 0)return w;
        if (wt[w] < ans)ans = wt[w];
        return dfs(cd[w]);
    }

    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){
        this->n=n;
        this->p=p;
        rd=vector<int>(n+1);
        wt=vector<int>(n+1);
        cd=vector<int>(n+1);
        vector<vector<int>> res;
        int i = 0;
        while (i < p) {
            int q = a[i], h = b[i],
            t = d[i];
            cd[q] = h;
            wt[q] = t;
            rd[h] = q;
            i++;
        }
        for (int j = 1; j <= n; ++j)
            if (rd[j] == 0 && cd[j]) {
                ans = 1000000000;
                int w = dfs(j);
                res.push_back({j,w,ans});
        }
        return res;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, p;
        cin>>n>>p;
        vector<int>a(p), b(p), d(p);
        for(int i = 0;i<p;i++)cin>>a[i]>>b[i]>>d[i];
        Solution ob;
        vector<vector<int>>answer = ob.solve(n, p, a, b, d);
        cout<<answer.size()<<endl;
        for(auto i : answer)cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    return 0;
}

/* input

1
9 6
7 4 98
5 9 72
4 6 10
2 8 22
9 7 17
3 1 66

output

3
2 8 22
3 1 66
5 6 10

*/