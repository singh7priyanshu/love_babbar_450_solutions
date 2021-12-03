/*
Implement two stacks in an array

Your task is to implement  2 stacks in one array efficiently.

 

Example 1:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()

Output:
3 4 -1

Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push2(4) the stack2 will be {4}
pop1()   the poped element will be 3 
from stack1 and stack1 will be {2}
pop2()   the poped element will be 4 
from stack2 and now stack2 is empty
pop2()   the stack2 is now empty hence -1 .
 

Your Task:
You don't need to read input or print anything. You are required to complete the 4 methods push1, 
push2 which takes one argument an integer 'x' to be pushed into stack one and two and pop1, 
pop2 which returns the integer poped out from stack one and two. 
If no integer is present in the array return -1.

 

Expected Time Complexity: O(1) for all the four methods.
Expected Auxiliary Space: O(1) for all the four methods.

 

Constraints:
1 <= Number of queries <= 100
1 <= value in the stack <= 100
The sum of elements in both the stacks < size of the given array

*/

import java.util.*;
class TwoStack{
    int size;
    int top1,top2;
    int arr[] = new int[100];

    TwoStack(){
        int n = 100;
        size = n;
        top1 = -1;
        top2 = size;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0){
            TwoStack sq = new TwoStack();
             
            int Q = sc.nextInt();
            while(T>0){
                int stack_no = sc.nextInt();
                int QueryType = sc.nextInt();

                Stacks g = new Stacks();

                if(QueryType == 1){
                    int a = sc.nextInt();
                    if(stack_no == 1)g.push1(a,sq);
                    else if(stack_no == 2)g.push2(a,sq);
                }else if(QueryType == 2){
                    if(stack_no == 1)System.out.print(g.pop1(sq)+" ");
                    else if(stack_no == 2)System.out.print(g.pop2(sq)+" ");
                }
                Q--;
            }
            System.out.println();
            T--;
        }
    }
}

//The idea is to start two stacks from two extreme corners of arr[].
//stack1 starts from the leftmost element, the first element in stack1 is 
//pushed at index 0. The stack2 starts from the rightmost corner, the first
//element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) 
//in opposite direction. To check for overflow, all we need to check is for 
//space between top elements of both stacks.


class Stacks
{
    //Function to push an integer into the stack1.
	void push1(int x,TwoStack sq)
	{
	    //if there is space between the top of both stacks 
        //we push the element at top1+1.
		if(sq.top1 < sq.top2 - 1)
		{
			sq.top1++;
			sq.arr[sq.top1] = x;
		}
	}
	
	//Function to push an integer into the stack2.
	void push2(int x, TwoStack sq)
	{
		//if there is space between the top of both stacks 
        //we push the element at top2-1.
		if(sq.top1 < sq.top2 -1)
		{
			sq.top2--;
			sq.arr[sq.top2] = x;
		}
	}

    //Function to remove an element from top of the stack1.
	int pop1(TwoStack sq)
	{
	    //if top1==-1, stack1 is empty so we return -1 else we 
        //return the top element of stack1.
		if(sq.top1 >= 0)
		{
			int x = sq.arr[sq.top1];
			sq.top1--;
			return x;
		}
		else
			return -1;
	}
	
	//Function to remove an element from top of the stack2.
	int pop2(TwoStack sq)
	{
		//if top2==size of array, stack2 is empty so we return -1 else we 
        //return the top element of stack2.
		if(sq.top2 < sq.size)
		{
			int x =sq.arr[sq.top2];
			sq.top2++;
			return x;
		}
		else
			return -1;
	}
}