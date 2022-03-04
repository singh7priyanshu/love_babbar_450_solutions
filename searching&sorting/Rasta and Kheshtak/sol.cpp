/*
Rasta and Kheshtak

Rasta is a big fan of Kheshtaks. A Kheshtak is a rectangle that in each of 
it cells there is an integer.

Today rasta came up with an interesting problem, Biggest Common Subsquare (BCS). 
A Kheshtak is called a Square if the number of its columns is equal to the number 
of its rows. A Square S is called a subsqaue of a Kheshtak A if and only if we 
can turn A to S by deleting some of its rows and some of its columns (maybe none).

He gives you two Kheshtaks, A and B (A one is n × m and B is x × y).

Input format
The first line of input contains n and m.
Then you are given A (n lines, in each line there are m space separated integers).
After that you are given x and y.
Then you are given B (x lines, in each line there are y space separated integers).

1 ≤ n, m, x, y ≤ 700 and all numbers in A and B are integers in the interval [1, 1000].

Output format
Print the size of BCS of A and B in a single line (size of a Square is number of its rows).

Sample Input
3 3
1 2 0
1 2 1
1 2 3
3 3
0 1 2
1 1 2
3 1 2
Sample Output
2
Time Limit: 2
Memory Limit: 256
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define double long double
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 710;
int a[2][maxn][maxn];
int n[2], m[2];
int h[2][maxn][maxn], H[2][maxn][maxn];
int p = 29 * 91, pw[maxn];
int p2 = 701, pw2[maxn];
inline void init(int x){
    For(i,0,n[x]){
        int cur = 0;
        For(j,0,m[x]){
            cur = (cur * 1LL * p);
            cur = (cur + a[x][i][j]);
            h[x][i][j] = cur;
        }
    }
}
inline int hashrow(int x,int row,int l,int r){
    int ans = h[x][row][r];
    if(l){
        int X = (1LL * pw[r - l + 1] * h[x][row][l-1]);
        ans = (ans - X);
    }
    return ans;
}
inline int hashcol(int x,int col,int l,int r){
    int ans = H[x][col][r];
    if(l){
        int X = (1LL * pw2[r - l + 1] * H[x][col][l-1]);
        ans = (ans - X);
    }
    return ans;
}
inline bool check(int s){
    if(!s)  return true;
    if(s > min(min(m[0], m[1]), min(n[0], n[1])))   return false;
    memset(H, 0, sizeof H);
    For(x,0,2)
        For(j,0,m[x]){
            int l = max(0LL, j - s + 1);
            int cur = 0;
            For(i, 0, n[x]){
                int w = hashrow(x, i, l, j);
                cur = (cur * 1LL * p2);
                cur = (cur + w);
                H[x][j][i] = cur;
                //if(j)
                //Error(cur, w);
            }
        }
    vi mp;
    For(x,0,2){
        For(j,s-1,m[x])
        For(i,s-1,n[x]){
            int h = hashcol(x, j, i - s + 1, i);
            //error(x);
            //Error(i, j);
            //error(H[x][j][i]);
            //error(h);
            if(!x)
                mp.pb(h);
            else{
                int x = lower_bound(all(mp), h) - mp.begin();
                if(x >= 0 && x < (int)mp.size() && mp[x] == h)
                    return true;
            }
        }
        if(!x){
            sort(all(mp));
            mp.resize(unique(all(mp)) - mp.begin());
        }
    }
    return false;
}
int ans = 1e9;
main(){
    iOS;
    pw[0] = pw2[0] = 1;
    For(i,1,maxn)
        pw[i] = (pw[i-1] * p), pw2[i] = (pw2[i-1] * p2);
        For(x,0,2){
            cin >> n[x] >> m[x];
            For(i,0,n[x])
                For(j,0,m[x])
                {cin >> a[x][i][j]; a[x][i][j] += 16;}
            init(x);
        }
        int l = 0, r = min(min(n[0], n[1]), min(m[0], m[1])) + 1;
        while(r - l > 1){
            int mid = (l+r)/2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        smin(ans, l);
    cout << ans << endl;

}