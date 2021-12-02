/*
Reverse Level Order Traversal

METHOD 1 (Recursive function to print a given level) 
We can easily modify the method 1 of the normal level order traversal. 
In method 1, we have a method printGivenLevel() which prints a given level number. 
The only thing we need to change is, instead of calling printGivenLevel() from the first 
level to the last level, we call it from the last level to the first level. 

*/

// A recursive C++ program to print
// REVERSE level order traversal
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left and right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/*Function prototypes*/
void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

/* Function to print REVERSE
level order traversal a tree*/
void reverseLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
		printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

/* Driver code*/
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;

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


// A C++ program to print REVERSE level order traversal using stack and queue
// This approach is adopted from following link
// http://tech-queries.blogspot.in/2008/12/level-order-tree-traversal-in-reverse.html
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left and right children */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Given a binary tree, print its nodes in reverse level order */
void reverseLevelOrder(node* root)
{
	stack <node *> S;
	queue <node *> Q;
	Q.push(root);

	// Do something like normal level order traversal order. Following are the
	// differences with normal level order traversal
	// 1) Instead of printing a node, we push the node to stack
	// 2) Right subtree is visited before left subtree
	while (Q.empty() == false)
	{
		/* Dequeue node and make it root */
		root = Q.front();
		Q.pop();
		S.push(root);

		/* Enqueue right child */
		if (root->right)
			Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT

		/* Enqueue left child */
		if (root->left)
			Q.push(root->left);
	}

	// Now pop all items from stack one by one and print them
	while (S.empty() == false)
	{
		root = S.top();
		cout << root->data << " ";
		S.pop();
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}

/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}


/*

Output: 

Level Order traversal of binary tree is
4 5 6 7 2 3 1
Time Complexity: O(n) where n is the number of nodes in the binary tree. 

*/