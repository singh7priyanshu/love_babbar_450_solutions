"""
Binary Search Tree | Set 1 (Search and Insertion)

The following is the definition of Binary Search Tree(BST) according to Wikipedia
Binary Search Tree is a node-based binary tree data structure which has the following properties:  

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree. 
There must be no duplicate nodes.

The above properties of Binary Search Tree provides an ordering among keys 
so that the operations like search, minimum and maximum can be done fast. 
If there is no ordering, then we may have to compare every key to search for a given key.

 
Searching a key 
For searching a value, if we had a sorted array we could have performed a binary search. 
Let’s say we want to search a number in the array what we do in binary search is we first define the complete 
list as our search space, the number can exist only within the search space. 
Now we compare the number to be searched or the element to be searched with the mid 
element of the search space or the median and if the record being searched is 
lesser we go searching in the left half else we go searching in the right half, 
in case of equality we have found the element. In binary search we start with ‘n’ elements 
in search space and then if the mid element is not the element that we are looking for,
we reduce the search space to ‘n/2’ and we go on reducing the search space till 
we either find the record that we are looking for or we get to only one element 
in search space and be done with this whole reduction. 

Search operation in binary search tree will be very similar. 
Let’s say we want to search for the number, what we’ll do is we’ll start at the root, 
and then we will compare the value to be searched with the value of the root if 
it’s equal we are done with the search if it’s lesser we know that we need to go 
to the left subtree because in a binary search tree all the elements in the left 
subtree are lesser and all the elements in the right subtree are greater. 
Searching an element in the binary search tree is basically this traversal
in which at each step we will go either towards left or right and hence in at 
each step we discard one of the sub-trees. 
If the tree is balanced, we call a tree balanced if for all nodes 
the difference between the heights of left and right subtrees is not greater than one, 
we will start with a search space of ‘n’nodes and when we will discard one of the sub-trees 
we will discard ‘n/2’ nodes so our search space will be reduced to ‘n/2’ and 
then in the next step we will reduce the search space to ‘n/4’ and we will go on 
reducing like this till we find the element or till our search space is reduced to only one node. 
The search here is also a binary search and that’s why the name binary search tree.

"""

# A utility function to search a given key in BST
def search(root,key):
	
	# Base Cases: root is null or key is present at root
	if root is None or root.val == key:
		return root

	# Key is greater than root's key
	if root.val < key:
		return search(root.right,key)

	# Key is smaller than root's key
	return search(root.left,key)

"""



Illustration to search 6 in below tree: 
1. Start from the root. 
2. Compare the searching element with root, if less than root, then recurse for left, else recurse for right. 
3. If the element to search is found anywhere, return true, else return false. 


Insertion of a key 
A new key is always inserted at the leaf. We start searching a key from the root until we hit a leaf node. 
Once a leaf node is found, 
the new node is added as a child of the leaf node. 

         100                               100
        /   \        Insert 40            /    \
      20     500    --------->          20     500 
     /  \                              /  \  
    10   30                           10   30
                                              \   
                                              40
                                        
"""

# Python program to demonstrate
# insert operation in binary search tree

# A utility class that represents
# an individual node in a BST


class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key

# A utility function to insert
# a new node with the given key


def insert(root, key):
	if root is None:
		return Node(key)
	else:
		if root.val == key:
			return root
		elif root.val < key:
			root.right = insert(root.right, key)
		else:
			root.left = insert(root.left, key)
	return root

# A utility function to do inorder tree traversal


def inorder(root):
	if root:
		inorder(root.left)
		print(root.val)
		inorder(root.right)


# Driver program to test the above functions
# Let us create the following BST
# 50
# /	 \
# 30	 70
# / \ / \
# 20 40 60 80

r = Node(50)
r = insert(r, 30)
r = insert(r, 20)
r = insert(r, 40)
r = insert(r, 70)
r = insert(r, 60)
r = insert(r, 80)

# Print inoder traversal of the BST
inorder(r)

"""

Output
20
30
40
50
60
70
80
Illustration to insert 2 in below tree: 
1. Start from the root. 
2. Compare the inserting element with root, if less than root, then recurse for left, else recurse for right. 
3. After reaching the end, just insert that node at left(if less than current) else right. 

"""

import java.util.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		BST tree=new BST();
		tree.insert(30);
		tree.insert(50);
		tree.insert(15);
		tree.insert(20);
		tree.insert(10);
		tree.insert(40);
		tree.insert(60);
		tree.inorder();
	}
}

class Node{
	Node left;
	int val;
	Node right;
	Node(int val){
		this.val=val;
	}
}

class BST{
Node root;

public void insert(int key){
		Node node=new Node(key);
		if(root==null) {
			root = node;
			return;
		}
		Node prev=null;
		Node temp=root;
		while (temp!=null){
			if(temp.val>key){
				prev=temp;
				temp=temp.left;
			}
			else if (temp.val<key){
				prev=temp;
				temp=temp.right;
			}
		}
		if(prev.val>key)
			prev.left=node;
		else prev.right=node;
	}

public void inorder(){
		Node temp=root;
		Stack<Node> stack=new Stack<>();
		while (temp!=null||!stack.isEmpty()){
			if(temp!=null){
				stack.add(temp);
				temp=temp.left;
			}
			else {
				temp=stack.pop();
				System.out.print(temp.val+" ");
				temp=temp.right;
			}
		}
	}
}

"""

Output
10 15 20 30 40 50 60 
 
Some Interesting Facts:  

Inorder traversal of BST always produces sorted output.
We can construct a BST with only Preorder or Postorder or Level Order traversal. 
Note that we can always get inorder traversal by sorting the only given traversal.
Number of unique BSTs with n distinct keys is Catalan Number

"""