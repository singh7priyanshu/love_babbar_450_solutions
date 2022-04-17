/*
Print all possible paths from top left to bottom right of a mXn matrix

The problem is to print all the possible paths 
from top left to bottom right of a mXn matrix 
with the constraints that from each cell you can 
either move only to right or down.

Examples : 

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
The algorithm is a simple recursive algorithm, 
from each cell first print all paths by going 
down and then print all paths by going right. 
Do this recursively for each cell encountered.

Following are implementation of the above algorithm. 
*/

// C++ program to Print all possible paths from
// top left to bottom right of a mXn matrix
#include<iostream>

using namespace std;

/* mat: Pointer to the starting of mXn matrix
i, j: Current position of the robot (For the first call use 0,0)
m, n: Dimensions of given the matrix
pi: Next index to be filed in path array
*path[0..pi-1]: The path traversed by robot till now (Array to hold the
				path need to have space for at least m+n elements) */
void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path, int pi)
{
	// Reached the bottom of the matrix so we are left with
	// only option to move right
	if (i == m - 1)
	{
		for (int k = j; k < n; k++)
			path[pi + k - j] = *((mat + i*n) + k);
		for (int l = 0; l < pi + n - j; l++)
			cout << path[l] << " ";
		cout << endl;
		return;
	}

	// Reached the right corner of the matrix we are left with
	// only the downward movement.
	if (j == n - 1)
	{
		for (int k = i; k < m; k++)
			path[pi + k - i] = *((mat + k*n) + j);
		for (int l = 0; l < pi + m - i; l++)
			cout << path[l] << " ";
		cout << endl;
		return;
	}

	// Add the current cell to the path being generated
	path[pi] = *((mat + i*n) + j);

	// Print all the paths that are possible after moving down
	printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1);

	// Print all the paths that are possible after moving right
	printAllPathsUtil(mat, i, j+1, m, n, path, pi + 1);

	// Print all the paths that are possible after moving diagonal
	// printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1);
}

// The main function that prints all paths from top left to bottom right
// in a matrix 'mat' of size mXn
void printAllPaths(int *mat, int m, int n)
{
	int *path = new int[m+n];
	printAllPathsUtil(mat, 0, 0, m, n, path, 0);
}

// Driver program to test above functions
int main()
{
	int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
	printAllPaths(*mat, 2, 3);
	return 0;
}

/*
Output
1 4 5 6 
1 2 5 6 
1 2 3 6 
Note that in the above code, the last line of 
printAllPathsUtil() is commented, If we uncomment 
this line, we get all the paths from the top left to 
bottom right of a nXm matrix 

if the diagonal movements are also allowed. 

And also if moving to some of the cells are not 
permitted then the same code can be improved by 
passing the restriction array to the above function 
and that is left as an exercise.

*/
// C++ program to Print all possible paths from
// top left to bottom right of a mXn matrix
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPaths;

void findPathsUtil(vector<vector<int>> maze, int m,
								int n, int i, int j,
						vector<int> path, int index)
{
	
	// If we reach the bottom of maze,
	// we can only move right
	if (i == m - 1)
	{
		for(int k = j; k < n; k++)
		{
			
			//path.append(maze[i][k])
			path[index + k - j] = maze[i][k];
		}
		
		// If we hit this block, it means one
		// path is completed. Add it to paths
		// list and print
		cout << "[" << path[0] << ", ";
		for(int z = 1; z < path.size() - 1; z++)
		{
			cout << path[z] << ", ";
		}
		cout << path[path.size() - 1] << "]" << endl;
		allPaths.push_back(path);
		return;
	}
		
	// If we reach to the right most
	// corner, we can only move down
	if (j == n - 1)
	{
		for(int k = i; k < m; k++)
		{
			path[index + k - i] = maze[k][j];
		}
		
		//path.append(maze[j][k])
		// If we hit this block, it means one
		// path is completed. Add it to paths
		// list and print
		cout << "[" << path[0] << ", ";
		for(int z = 1; z < path.size() - 1; z++)
		{
			cout << path[z] << ", ";
		}
		cout << path[path.size() - 1] << "]" << endl;
		allPaths.push_back(path);
		return;
	}
	
	// Add current element to the path list
	//path.append(maze[i][j])
	path[index] = maze[i][j];
	
	// Move down in y direction and call
	// findPathsUtil recursively
	findPathsUtil(maze, m, n, i + 1,
				j, path, index + 1);
	
	// Move down in y direction and
	// call findPathsUtil recursively
	findPathsUtil(maze, m, n, i, j + 1,
						path, index + 1);
}
	
void findPaths(vector<vector<int>> maze,
					int m, int n)
{
	vector<int> path(m + n - 1, 0);
	findPathsUtil(maze, m, n, 0, 0, path, 0);
}

// Driver Code
int main()
{
	vector<vector<int>> maze{ { 1, 2, 3 },
							{ 4, 5, 6 },
							{ 7, 8, 9 } };
	findPaths(maze, 3, 3);
	
	//print(allPaths)
	return 0;
}

/*
Output
[1, 4, 7, 8, 9]
[1, 4, 5, 8, 9]
[1, 4, 5, 6, 9]
[1, 2, 5, 8, 9]
[1, 2, 5, 6, 9]
[1, 2, 3, 6, 9]
Note all the above approach take some extra time 
and space for solving the problem ,we can simply use 
backtracking algorithm to solve problem in optimized manner 
*/

#include<bits/stdc++.h>
using namespace std;

// function to display the path
void display(vector<int> &ans) {
for(auto i :ans ) {
	cout<<i <<" ";
}
cout<<endl;
}

// a function which check whether our step is safe or not
bool issafe(int r,int c,vector<vector<int>>& visited,int n,int m) {
return (r < n and c <m and visited[r] !=-1 ); // return true if all values satisfied else false
}


void FindPaths(vector<vector<int>> &grid,int r,int c, int n,int m,vector<int> &ans) {
// when we hit the last cell we reach to destination then directly push the path
if(r == n-1 and c == m-1) {
	ans.push_back(grid[r]);
	display(ans); // function to display the path stored in ans vector
	ans.pop_back(); // pop back because we need to backtrack to explore more path
	return ;
}

// we will store the current value in ch and mark the visited place as -1
int ch = grid[r];

ans.push_back(ch); // push the path in ans array
grid[r] = -1; // mark the visited place with -1

// if is it safe to take next downward step then take it
if(issafe(r+1,c,grid,n,m)) {
	FindPaths(grid,r+1,c,n,m,ans);
}

// if is it safe to take next rightward step then take it
if(issafe(r,c+1,grid,n,m)) {
	FindPaths(grid,r,c+1,n,m,ans);
}

// backtracking step we need to make values original so to we can visit it by some another path
grid[r] = ch;

// remove the current path element we explore
ans.pop_back();
return ;
}

int main() {
	int n = 3 ,m =3;
	vector<vector<int> >grid{ {1,2,3},{4,5,6},{7,8,9}};
	vector<int>ans ; // it will store the path which we have covered
	
	FindPaths(grid,0,0,n,m,ans); // here 0,0 are initial position to start with
	return 0;
}

/*
Output
1 4 7 8 9 
1 4 5 8 9 
1 4 5 6 9 
1 2 5 8 9 
1 2 5 6 9 
1 2 3 6 9 
So by these method you can optimized your code.

TC- O(2^n*m)   , SC – O(n) 

Another Approach (Iterative) :

1. In this approach we will use BFS (breadth first search) 
to find all possible paths.

2. We will make a queue which contains the following information : 

    a)  Vector that stores the path up to a certain cell.

    b)  coordinates of the cell.

3. We will start from the top-left cell and push cell value 
    and coordinates in the queue.

4. We will keep on exploring right and down cell (if possible) 
    until queue is not empty 

   and push them in the queue by updating the current cell vector.

5. If we reach the last cell then we have got one answer and we 
    will print the answer vector.

*/

// c++ implementation for the above approach
#include <bits/stdc++.h>
using namespace std;

// this structure stores information
// about a particular cell i.e
// path upto that cell and cell's
// coordinates
struct info {
	vector<int> path;
	int i;
	int j;
};

void printAllPaths(vector<vector<int> >& maze)
{
	int n = maze.size();
	int m = maze[0].size();

	queue<info> q;
	// pushing top-left cell into the queue
	q.push({ { maze[0][0] }, 0, 0 });

	while (!q.empty()) {
		info p = q.front();
		q.pop();

		// if we reached the bottom-right cell
		// i.e the destination then print the path
		if (p.i == n - 1 && p.j == m - 1) {
			for (auto x : p.path)
				cout << x << " ";

			cout << "\n";
		}

		// if we are in the last row
		// then only right movement is possible
		else if (p.i == n - 1) {
			vector<int> temp = p.path;
			// updating the current path
			temp.push_back(maze[p.i][p.j + 1]);

			q.push({ temp, p.i, p.j + 1 });
		}

		// if we are in the last column
		// then only down movement is possible
		else if (p.j == m - 1) {
			vector<int> temp = p.path;
			// updating the current path
			temp.push_back(maze[p.i + 1][p.j]);

			q.push({ temp, p.i + 1, p.j });
		}

		// else both right and down movement
		// are possible
		else { // right movement
			vector<int> temp = p.path;
			// updating the current path
			temp.push_back(maze[p.i][p.j + 1]);

			q.push({ temp, p.i, p.j + 1 });

			// down movement
			temp.pop_back();
			// updating the current path
			temp.push_back(maze[p.i + 1][p.j]);

			q.push({ temp, p.i + 1, p.j });
		}
	}
}

// Driver Code
int main()
{
	vector<vector<int> > maze{ { 1, 2, 3 },
							{ 4, 5, 6 },
							{ 7, 8, 9 } };

	printAllPaths(maze);

	return 0;
}

/*
Output
1 2 3 6 9 
1 2 5 6 9 
1 2 5 8 9 
1 4 5 6 9 
1 4 5 8 9 
1 4 7 8 9 

*/