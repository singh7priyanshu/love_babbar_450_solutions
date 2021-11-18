"""
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

"""

class Solution:
    
    #Function to return a list of integers denoting spiral traversal of matrix.
    def spirallyTraverse(self,matrix, r, c): 
        # code here 
        row = 0 
        col = 0
        output = []
        while (row < r and col < c) : 
              
            #storing the elements of 1st row from the remaining rows, in a list.
            for i in range(col, c) : 
                output.append(matrix[row][i])      
            row += 1
      
            #storing elements of last column from remaining columns, in list.
            for i in range(row, r) : 
                output.append(matrix[i][c - 1]) 
            c -= 1
      
            #storing the elements of last row from remaining rows, in a list.
            if (row < r) : 
                for i in range(c - 1, (col - 1), -1) : 
                    output.append(matrix[r - 1][i]) 
                r -= 1
              
            #storing elements of 1st column from remaining columns, in list.
            if (col < c) : 
                for i in range(r - 1, row - 1, -1) : 
                    output.append(matrix[i][col]) 
                  
                col += 1
    
        #returning the list.
        return output


if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        r,c = map(int,input().strip().split())
        values = list(map(int,input().strip().split()))
        k=0
        matrix=[]
        for i in range(r):
            row=[]
            for j in range(c):
                row.append(values[k])
                k+=1
            matrix.append(row)
        obj=Solution()
        ans=obj.spirallyTraverse(matrix,r,c)
        for i  in ans:
            print(i,end=" ")
        print()