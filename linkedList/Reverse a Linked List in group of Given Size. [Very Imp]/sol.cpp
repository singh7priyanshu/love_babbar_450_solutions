/*
Given a linked list of size N. 
The task is to reverse every k nodes 
(where k is an input to the function) in the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
1 <= k <= N
*/


#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;

    node(int x){
        data=x;
        next=NULL;
    }
};

void printList(struct node *node){
    while (node!= NULL){
        printf("%d",node->data);
        node = node->next;
    }
    printf("\n");
}

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node* current = head;
    	struct node* next = NULL;
    	struct node* prev = NULL;
    	int count = 0; 
    	
    	while (current != NULL && count < k)
    	// reversing k elements :
    	{
    		next = current->next;             // marking next node
    		current->next = prev;             // reversing link
    		prev = current;                   // updating prev
    		current = next;                   // updating current
    		count++;
    	}
    	
    	if (next != NULL)       // checking if there are nodes ahead
        	head->next = reverse(next, k);    // reversing those recursively
        
    	return prev; 
    }
};

int main(void){
    int t;
    cin>>t;
    while(t--){
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int value;
            cin>>value;
            if(i == 0){
                head = new node(value);
                temp = temp->next;
            }
            else{
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        int k;
        cin>>k;
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
    return 0;
}