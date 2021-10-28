	// binary tree
// inorder traversal and printing the result

#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = right = NULL;
	}
};


class Solution{
public:

	vector<int>inOrder(Node *root){

		if (root == NULL) return ;


		inOrder(root->left, res);
		res.push_back(root->data);
		inOrder(root->right, res);
	}


	vector<int>inOrder(Node* root){
		vector<int>res;
		inOrder(root,res);
		return res;
	}
};


// function to build the tree

Node* buildTree(string str){

	// corner case 
	if(str.length() == 0 || str[0] == 'N') return NULL;

	// creating vector of strings from input
	//string after splitting by space

	vector<string>ip;
	istringstream iss(str);
	for(string str; iss >> str;) ip.push_back(str);

	// Create the root of the tree 
	 Node* root = new Node(stoi(ip[0]));

	// push the root to the queue
	queue<Node*>queue;
	queue.push(root);

	// starting from the second element 
	int i = 1;
	while(!queue.empty() && i < ip.size()){

		// get and remove the front of the queue 
		Node* currNode = queue.front();
		queue.pop();

		//get the current node's value from the string
		string currVal = ip[i];

		// if the left child is not NULL 
		if(currVal != "N"){

			// create the left child for the current node
			currNode -> left = new Node(stoi(currVal));

			// push it to the queue
			queue.push(currNode -> left);

		}

		// for the right child
		i++;
		if(i >= ip.size()) break ;
		currVal = ip[i];

		// if the right child is not NULL
		if(currVal != "N"){

			// create the right child for the current node
			currNode -> right = new Node(stoi(currVal));

			// push it to the queue 
			queue.push(currNode -> right);
		}
		i++;

	}

	return root;

}

int main (){
	int t ;
	string tc;
	getline (cin, tc);
	t = stoi(tc);
	while(t--){
		string s;
		getline(cin, s);
		Node* root = buildTree(s);

		// calling for the function inOrder traversal and print the result 
		Solution ob;
		vector<int>res = ob.inOrder(root);
		for(int i=0;i<res.size();i++) cout<<res[i]<< " ";
		cout << endl;
	}
	 return 0;
}