/*
DEFKIN -Defense of a Kingdom

https://www.spoj.com/problems/DEFKIN/

Theodore implements a new strategy game “Defense of a Kingdom”. 
On each level a player defends the Kingdom that is represented 
by a rectangular grid of cells. 

The player builds crossbow towers in some cells of the grid. 
The tower defends all the cells in the same row and the 
same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the 
largest undefended rectangle. For example, the position 
shown on the picture has penalty 12.

Help Theodore write a program that calculates the penalty 
of the given position.

Input
The first line of the input file contains the number of
test cases.

Each test case consists of a line with three integer 
numbers: 
w — width of the grid, 
h — height of the grid and 
n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

Each of the following n lines contains two integer 
numbers xi and yi — the coordinates of the cell occupied by 
a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output
For each test case, output a single integer number — the 
number of cells in the largest rectangle that is not 
defended by the towers.

Example
Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> x, y;
 
int main() {
    int t;
    cin >> t;
    
    int n, m, q;
    while(t--) {
        cin >> n >> m >> q;
        
        x.clear();
        x.resize(q + 2);
        y.clear();
        y.resize(q + 2);
        
        x[0] = 0;
        y[0] = 0;
        
        for(int i = 1; i <= q; i++)
            cin >> x[i] >> y[i];
        
        x[x.size() - 1] = n + 1;
        y[y.size() - 1] = m + 1;
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int mxx = 0, mxy = 0;
        
        for(int i = 0; i < x.size() - 1; i++) {
            mxx = max(mxx, x[i+1] - x[i] - 1);
            mxy = max(mxy, y[i+1] - y[i] - 1);
        }
        
        cout << mxx * mxy << endl;
    }
    
    return 0;
} 