/*
662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes 
(the leftmost and rightmost non-null nodes), where the null nodes between 
the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

 

Example 1:
            (1)
           /   \ 
        (3)     (2)
        /  \       \
      (5)  (3)      (9)

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:

           (1)
          /
        (3)
       /   \
    (5)     (3)


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:

             (1)
            /   \
          (3)    (2)
         /
       (5)  

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        
        // I am using intialising list
        q.push({root, 0});      // also can use make_pair
        
        while(!q.empty())
        {
            int cnt = q.size();
            // start is the index of root node for first level
            int start = q.front().second;
            int end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                // we will use it while inserting it children
                // left child will be 2 * idx + 1;
                // right chils will be 2 * idx + 2;
                int idx = p.second - start;
                
                q.pop();
                
                // if  left child exist
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                // if right child exist
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return res;
        
    }
};

/*
1.  According to Problem , we have also to count null nodes b/w two nodes.

		  5					1
	     / \
	    3   6				2
	   /   /
	  2   4					2

2.  Above example we have max 2 nodes in a level, but if you see the second level you
will find that right child of 3 is NULL and therefore we also have to count that 
NULL node, and with that the last level now contain 3 nodes, refer to diagram below.

	      5					1
	   /     \
	   3      6				2
	 /  \    /
	2  NULL  4				3 (NULL node also counted)

So Last Level Contains 3 Nodes Including NULL.

3 . We will also assign index to every node

	(if we are startting index from 0)
	according to binary heap

	left(idx) = 2 idx + 1			// left child
	right(idx) = 2 idx + 2			// right child


we will also insert index with node , so that we will know,
the first element at index __ & the last node is at index __
LET CONSIDER THE DRY RUN FOR ABOVE EXAMPLE
	      5					    1
	   /     \
	   3      6					2
	 /  \    /
	2  NULL  4				    3 (NULL node also counted)


if root is empty // return NULL

insert(5, 0) in queue,  queue is not empty
we will continue.

res = 1; 

1. pop(5,0);

	now we look at size of queue, size is one therefore
	and now we will insert,
	left and right child of popped node that is 5 in this case
	therefore,  
2. (3,1) , (6,2)  is inserted.

when we will finish with one iteration,
we will see the index of first element and index of last element in the current level..

i.e difference,

(2 - 1) + 1 and we will assign this to result.

so we will check  as,   res  = max(res, endIdx - startIdx + 1)
				res  = max(0, (2-1) + 1)
				res  = 2

3. Now (3,1)  is poped and its left and right child will be inserted.

	i.e (2,3)  its right is empty it will not insert

   Poped (6,2)
	and now right & left child of (6,2) will inserted.

	i.e (4,5) its right is empty it will not insert,

now at this level the startIdx is 3 (2,3)  & the endIndx is 5

therefore res = max(res  = max(res, endIdx - startIdx + 1)
	    res = max(2, (5-3) + 1)
	    res = 3

4. Now we will pop it and now there is nothing to push.

So finally we will return the result... (3)


As tree is Going Exponentially so we can come accross signed overflow,
therefore for preventing that we will do,

	int idx = p.second - start;

as we don't need  previous values. also we will type cast 2 * idx to  long long
AS EACH NODE IS VISITED ONCE
Time Complexity O(N)
Space Comlexity O(N)

*/