/*
Reverse Level Order Traversal

METHOD 1 (Recursive function to print a given level) 
We can easily modify the method 1 of the normal level order traversal. 
In method 1, we have a method printGivenLevel() which prints a given level number. 
The only thing we need to change is, instead of calling printGivenLevel() from the first 
level to the last level, we call it from the last level to the first level. 

*/

// A recursive java program to print reverse level order traversal

// A binary tree node
class Node
{
	int data;
	Node left, right;
	
	Node(int item)
	{
		data = item;
		left = right;
	}
}

class BinaryTree
{
	Node root;

	/* Function to print REVERSE level order traversal a tree*/
	void reverseLevelOrder(Node node)
	{
		int h = height(node);
		int i;
		for (i = h; i >= 1; i--)
		//THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
		{
			printGivenLevel(node, i);
		}
	}

	/* Print nodes at a given level */
	void printGivenLevel(Node node, int level)
	{
		if (node == null)
			return;
		if (level == 1)
			System.out.print(node.data + " ");
		else if (level > 1)
		{
			printGivenLevel(node.left, level - 1);
			printGivenLevel(node.right, level - 1);
		}
	}

	/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
	int height(Node node)
	{
		if (node == null)
			return 0;
		else
		{
			/* compute the height of each subtree */
			int lheight = height(node.left);
			int rheight = height(node.right);

			/* use the larger one */
			if (lheight > rheight)
				return (lheight + 1);
			else
				return (rheight + 1);
		}
	}

	// Driver program to test above functions
	public static void main(String args[])
	{
		BinaryTree tree = new BinaryTree();

		// Let us create trees shown in above diagram
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);
		
		System.out.println("Level Order traversal of binary tree is : ");
		tree.reverseLevelOrder(tree.root);
	}
}

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

// A recursive java program to print reverse level order traversal
// using stack and queue

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/* A binary tree node has data, pointer to left and right children */
class Node
{
	int data;
	Node left, right;

	Node(int item)
	{
		data = item;
		left = right;
	}
}

class BinaryTree
{
	Node root;

	/* Given a binary tree, print its nodes in reverse level order */
	void reverseLevelOrder(Node node)
	{
		Stack<Node> S = new Stack();
		Queue<Node> Q = new LinkedList();
		Q.add(node);

		// Do something like normal level order traversal order.Following
		// are the differences with normal level order traversal
		// 1) Instead of printing a node, we push the node to stack
		// 2) Right subtree is visited before left subtree
		while (Q.isEmpty() == false)
		{
			/* Dequeue node and make it root */
			node = Q.peek();
			Q.remove();
			S.push(node);

			/* Enqueue right child */
			if (node.right != null)
				// NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
				Q.add(node.right);
				
			/* Enqueue left child */
			if (node.left != null)
				Q.add(node.left);
		}

		// Now pop all items from stack one by one and print them
		while (S.empty() == false)
		{
			node = S.peek();
			System.out.print(node.data + " ");
			S.pop();
		}
	}

	// Driver program to test above functions
	public static void main(String args[])
	{
		BinaryTree tree = new BinaryTree();

		// Let us create trees shown in above diagram
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);
		tree.root.right.left = new Node(6);
		tree.root.right.right = new Node(7);

		System.out.println("Level Order traversal of binary tree is :");
		tree.reverseLevelOrder(tree.root);

	}
}

/*

Output: 

Level Order traversal of binary tree is
4 5 6 7 2 3 1
Time Complexity: O(n) where n is the number of nodes in the binary tree. 

*/