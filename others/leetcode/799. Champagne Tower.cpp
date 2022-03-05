/*
799. Champagne Tower

https://leetcode.com/problems/champagne-tower/


We stack glasses in a pyramid, where the first row has 1 glass, 
the second row has 2 glasses, and so on until the 100th row.  
Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  
When the topmost glass is full, any excess liquid poured will fall 
equally to the glass immediately to the left and right of it.  
When those glasses become full, any excess champagne will fall 
equally to the left and right of those glasses, and so on.  
(A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most 
glass is full.  After two cups of champagne are poured, the two 
glasses on the second row are half full.  After three cups of 
champagne are poured, those two cups become full - there are 3 
full glasses total now.  After four cups of champagne are poured, 
the third row has the middle glass half full, and the two outside 
glasses are a quarter full, as pictured below.



Now after pouring some non-negative integer cups of champagne, 
return how full the jth glass in the ith row is (both i and j are 0-indexed.)

 

Example 1:

Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the 
tower (which is indexed as (0, 0)). There will be no excess liquid 
so all the glasses under the top glass will remain empty.

Example 2:

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the 
tower (which is indexed as (0, 0)). There is one cup of excess liquid. 
The glass indexed as (1, 0) and the glass indexed as (1, 1) will share 
the excess liquid equally, and each will get half cup of champange.

Example 3:

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000
 

Constraints:

0 <= poured <= 109
0 <= query_glass <= query_row < 100
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<double> curr(query_row+1,0), next(query_row+1,0), clear(query_row+1,0);
        curr[0]=(double) poured;       
        for(int i=1; i<=query_row; i++){
            for(int j=0; j<i; j++)next[j]+=next[j+1]+= max( (curr[j]-1)/2, 0.0);       
            curr=next;  next=clear;    
        }
        return min( 1.0, curr[query_glass]);//flow>=1 => glass is full
    }
};

/*
class Solution {
public:
double champagneTower(int poured, int query_row, int query_glass) {
        
        //dp matrix
        double v[101][101] = {0.0};
    
        // as first glass will be poured always
        // ans overflow will be flowed to next level
        v[0][0] = poured;
    
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // If the glass >=1
                if (v[i][j] >= 1)
                {
                    // split  (v[i][j] - 1) into next level
                    v[i + 1][j]     += (v[i][j] - 1) / 2.0;
                    v[i + 1][j + 1] += (v[i][j] - 1) / 2.0;
                    v[i][j] = 1;
                }
            }
        }
        return v[query_row][query_glass];
    }
};

Because we just need the flow of the current row to calculate flow of 
the next row, we don't need to maintain an NxN 2D matrix.
*/