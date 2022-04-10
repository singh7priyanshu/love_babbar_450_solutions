/*
m Coloring Problem

Given an undirected graph and an integer M. 
The task is to determine if the graph can be colored 
with at most M colors such that no two adjacent 
vertices of the graph are colored with the same color. 

Here coloring of a graph means the assignment of colors 
to all vertices. 

Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.


Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0


Your Task:
Your task is to complete the function graphColoring() 
which takes the 2d-array graph[], the number of colours 
and the number of nodes as inputs and returns true if 
answer exists otherwise false. 

1 is printed if the returned value is true, 0 otherwise. 

The printing is done by the driver's code.

Note: In Example there are Edges not the graph.
Graph will be like, if there is an edge between vertex X 
and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. 

In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.
Function will be contain 2-D graph not the edges.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 20
1 ≤ E ≤ (N*(N-1))/2
1 ≤ M ≤ N
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
    //checking if the connected nodes to v have same colour as c.
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i]) return false;
    //returning true if no connected node has same colour.
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v,
                       int V) {
    //if all vertices have been assigned colour then we return true.
    if (v == V) return true;
    for (int c = 1; c <= m; c++){
        //checking if this colour can be given to a particular node.
        if (isSafe(v, graph, color, c, V)){
            //assigning colour to the node.
            color[v] = c;
            //calling function recursively and checking if other nodes 
            //can be assigned other colours.
            if (graphColoringUtil(graph, m, color, v + 1, V) == true)  return true; 
                //returning true if the current allocation was successful.
            //if not true, we backtrack and remove the colour for that node.
            color[v] = 0;
        }
    }
    //if no colour can be assigned, we return false.
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V){
    int *color = new int[V];
    for (int i = 0; i < V; i++) color[i] = 0;
    //checking if colours can be assigned.
    if (graphColoringUtil(graph, m, color, 0, V) == false)return false;
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n, m, e; cin>>n>>m>>e;
        bool graph[101][101];
        for(int i = 0;i<e;i++)memset(graph[i], 0, sizeof(graph[i]));
        for(int i = 0;i<e;i++){
            int a, b; cin>>a>>b;
            graph[a-1][b-1] = 1;
            graph[b-1][a-1] = 1;
        }
        cout<<graphColoring(graph, m, n)<<endl;
    }
    return 0;
}