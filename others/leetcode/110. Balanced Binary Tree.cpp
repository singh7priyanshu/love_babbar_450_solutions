/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of 
every node differ in height by no more than 1.

 

Example 1:

                 (3)
               /     \
             (9)     (20)
                   /     \
                 (15)    (7)
                

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

                            (1)
                          /    \
                        (2)    (2)
                      /     \
                    (3)     (3)
                  /    \
                (4)    (4)

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), 
 *     left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(rightHeight==-1||leftHeight ==-1)return -1;
        if(abs(leftHeight-rightHeight)>1)return -1;
        return max(leftHeight , rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        int ans = height(root);
        if(ans==-1)return false;
        else return true;    
    }
};