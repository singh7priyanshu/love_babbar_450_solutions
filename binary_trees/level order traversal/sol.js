/*
Level order traversal

Level order traversal

Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

*/


'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = ' ';
let currentLine = 0;

process.stdin.on('data',inputStdin =>{
    inputString += inputStdin;
});

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

class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function buildTree(str){
    //Corner Case
    if(str.length === 0 || str[0] === "N")
        return null;
    
    // Create the root of the tree
    let root = new Node(parseInt(str[0]));

    // Push the root to the queue
    let queue = [];
    let start = 0;
    queue.push(root);

    // Starting from the second element
    let i=1;
    while(queue.length !== start && i<str.length){
        //Get and remove the front of the queue
        let currNode = queue[start];
        start++;

        //Get the current node's value from the string
        let currVal = str[i];

        //If the left child is not null
        if(currVal !== "N"){

            // Create the left child for the current node
            currNode.left = new Node(parseInt(currVal));

            // Push it to the queue
            queue.push(currNode.left);
        }
        // For the right child
        i++;
        if(i>=str.length)
            break;
        currVal = str[i];

        // If the right child is not null
        if(currVal !== "N"){
            //Create the right child for the current node
            currNode.right = new Node(parseInt(currVal));

            // Push it to the queue
            queue.push(currNode.right);
        }
        i++;
    }
    return root;
}

function main(){
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++){
        let input_ar1 = readLine().split(' ');
        let root = buildTree(input_ar1);
        let obj = new Solution();
        let res = obj.levelOrder(root);
        let s = '';
        for(let i=0; i<res.length;i++){
            s+= res[i]+" ";
        }
        console.log(s);
    }
}

/**
 * @param {Node} node
 * @returns {number[]}
*/

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    //Function to return the level order traversal of a tree.
    levelOrder(node)
    {
        //your code here
                let res = [];
        //if node is null, we return the list. 
        if (node === null) 
        return res;
        
        //creating an empty queue for level order traversal.
        let q = [];
        let start_q = 0;
    
        
        q.push(node);
    
        while (q.length !== start_q)
        {
            //storing front element of queue in list and removing it from queue.
            let node1 = q[start_q]
            res.push(node1.data);
            start_q++;
    
            //storing the left child of the parent node in queue.
            if (node1.left !== null)
                q.push(node1.left);
    
            //storing the right child of the parent node in queue.
            if (node1.right !== null)
                q.push(node1.right);
        }
        //returning the list.
        return res;
    }
}