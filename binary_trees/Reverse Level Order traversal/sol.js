/*
Reverse Level Order Traversal

METHOD 1 (Recursive function to print a given level) 
We can easily modify the method 1 of the normal level order traversal. 
In method 1, we have a method printGivenLevel() which prints a given level number. 
The only thing we need to change is, instead of calling printGivenLevel() from the first 
level to the last level, we call it from the last level to the first level. 

*/


<script>

// A recursive JavaScript program to print
// reverse level order traversal
// A binary tree node
class Node {
    constructor(item) {
    this.data = item;
    this.left = null;
    this.right = null;
    }
}

class BinaryTree {
    constructor() {
    this.root = null;
    }

    /* Function to print REVERSE
    level order traversal a tree*/
    reverseLevelOrder(node) {
    var h = this.height(node);
    var i;
    for (
        i = h;
        i >= 1;
        i-- // THE ONLY LINE DIFFERENT // FROM NORMAL LEVEL ORDER
    ) {
        this.printGivenLevel(node, i);
    }
    }

    /* Print nodes at a given level */
    printGivenLevel(node, level) {
    if (node == null) return;
    if (level == 1) document.write(node.data + " ");
    else if (level > 1) {
        this.printGivenLevel(node.left, level - 1);
        this.printGivenLevel(node.right, level - 1);
    }
    }

    /* Compute the "height" of a tree --
    the number of nodes along the longest
    path from the root node down to the
    farthest leaf node.*/
    height(node) {
    if (node == null) return 0;
    else {
        /* compute the height of each subtree */
        var lheight = this.height(node.left);
        var rheight = this.height(node.right);

        /* use the larger one */
        if (lheight > rheight) return lheight + 1;
        else return rheight + 1;
    }
    }
}
// Driver Code
var tree = new BinaryTree();

// Let us create trees shown
// in above diagram
tree.root = new Node(1);
tree.root.left = new Node(2);
tree.root.right = new Node(3);
tree.root.left.left = new Node(4);
tree.root.left.right = new Node(5);

document.write(
"Level Order traversal " + "of binary tree is : <br>"
);
tree.reverseLevelOrder(tree.root);

</script>


/*

Output: 

Level Order traversal of binary tree is
4 5 2 3 1
Time Complexity: The worst-case time complexity of this method is O(n^2). 
For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes 
in the skewed tree. 
So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).


METHOD 2 (Using Queue and Stack) 
The method 2 of normal level order traversal can also be easily modified to print level order 
traversal in reverse order. The idea is to use a deque(double-ended queue) 
to get the reverse level order. A deque allows insertion and deletion at both the ends. 
If we do normal level order traversal and instead of printing a node, push the node to a 
stack and then print the contents of the deque, we get “5 4 3 2 1” for the above example tree, 
but the output should be “4 5 2 3 1”. So to get the correct sequence (left to right at every level), 
we process children of a node in reverse order, we first push the right subtree to the deque, 
then process the left subtree.

*/

<script>

// A recursive javascript program to print
// reverse level order traversal
// using stack and queue

/* A binary tree node has data, pointer to left
and right children */
class Node
{
	constructor(item)
	{
		this.data = item;
		this.left = this.right=null;
	}
}

let root;

/* Given a binary tree, print its nodes in reverse level order */
function reverseLevelOrder(node)
{
		let S = [];
		let Q = [];
		Q.push(node);

		// Do something like normal
		// level order traversal order.Following
		// are the differences with normal
		// level order traversal
		// 1) Instead of printing a node,
		// we push the node to stack
		// 2) Right subtree is visited before left subtree
		while (Q.length != 0)
		{
			/* Dequeue node and make it root */
			node = Q[0];
			Q.shift();
			S.push(node);

			/* Enqueue right child */
			if (node.right != null)
				// NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
				Q.push(node.right);
				
			/* Enqueue left child */
			if (node.left != null)
				Q.push(node.left);
		}

		// Now pop all items from stack
		// one by one and print them
		while (S.length != 0)
		{
			node = S.pop();
			document.write(node.data + " ");
			
		}
}

// Driver program to test above functions
// Let us create trees shown in above diagram
root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

document.write("Level Order traversal of binary tree is :<br>");
reverseLevelOrder(root);


</script>

/*

Output: 

Level Order traversal of binary tree is
4 5 6 7 2 3 1
Time Complexity: O(n) where n is the number of nodes in the binary tree. 

*/

