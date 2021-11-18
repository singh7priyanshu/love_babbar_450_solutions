/*
Spirally traversing a matrix

Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.

Constraints:
1 <= r, c <= 100
0 <= matrixi <= 100

*/

//User function Template for javascript


'use strict';
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = ' ';
let currentLine = 0;

process.stdin.on('data',inputStdin =>{
    inputString += inputStdin;
});

process.stdin.on('end', _ =>{
    inputString = inputString.trim().split('\n').map(string =>{
        return string.trim();
    });
    main();
});

function readLine(){
    return inputString[currentLine++];
}

function main(){
    let t = parseInt(readline());
    for(let i=0;i<t;i++){
        let input_line = readLine().split(' ');
        let n = parseInt(input_line[0]);
        let m = parseInt(input_line[1]);

        input_line =readLine().split(' ');
        let matrix = new Array(n);
        for(let i=0;i<n;i++){
            let a = new Array(m);
            for(let j=0;j<m;j++){
                a[j] = parseInt(input_line[i*m+j]);
            }
            matrix[i] = a;
        }
        
        let obj = new Solution();
        let ans = obj.spirallyTraverse(matrix,n,m);
        let s = "";
        for(let i = 0;i<ans.length;i++){
            s+=ans[i];
            s+=" ";
        }
        console.log(s);
    }
}

/**
 * @param {number[][]} matrix
 * @param {number} r
 * @param {number} c
 * @returns {number[]}
*/
class Solution 
{
    //Function to return a list of integers denoting spiral traversal of matrix.
    spirallyTraverse(matrix, r, c)
    {
        // code here
                let row = 0;
        let col = 0;
        let output = new Array();
        
        while(row<r && col<c)
        {
           //storing the elements of 1st row from the remaining rows, in a list.
           for(let i=col; i<c; i++)
               output.push(matrix[row][i]);
           row++;
           
           //storing elements of last column from remaining columns, in list.
           for(let i=row; i<r; i++)
               output.push(matrix[i][c-1]);
           c--;
           
           //storing the elements of last row from remaining rows, in a list.
            if(row<r)
            {
                for(let i=c-1; i>=col; --i)
                    output.push( matrix[r-1][i]);
                r--;
            }
           
           //storing elements of 1st column from the remaining columns, in list.
            if(col<c)
            {
                for(let i=r-1; i>=row; --i)
                    output.push( matrix[i][col]);
                col++;    
            }   
        }
        //returning the list.
        return output;
    }
}