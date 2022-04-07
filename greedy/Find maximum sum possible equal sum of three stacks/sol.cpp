/*
Find maximum sum possible equal sum of three stacks

Given three stacks of the positive numbers, the task 
is to find the possible equal maximum sum of the stacks 
with the removal of top elements allowed. 

Stacks are represented as an array, and the first index 
of the array represent the top element of the stack.

Examples: 



Input : stack1[] = { 3, 10}
  stack2[] = { 4, 5 }
  stack3[] = { 2, 1 }
Output : 0
Sum can only be equal after removing all elements 
from all stacks.

input         output
3          By removing 3 of stack1, sum of stack1 = 8-3 =5
2
1
1
1

4          By removing 4 of stack2, sum of stack2 = 9-4 = 5
3
2

2          By removing 2 and 5 of stack3, sum of stack3 = 12-5-2 = 5
5
4
1


The idea is to compare the sum of each stack, if they 
are not same, remove the top element of the stack having 
the maximum sum.
Algorithm for solving this problem: 

1. Find the sum of all elements of in individual stacks.
2. If the sum of all three stacks is the same, then this is the maximum sum.
3. Else remove the top element of the stack having the maximum 
    sum among three of stacks. Repeat step 1 and step 2.

The approach works because elements are positive. To make sum equal, 
we must remove some element from stack having more sum, and we can 
only remove from the top.

Below is the implementation of this approach: 
*/
// C++ program to calculate maximum sum with equal
// stack sum.
#include <bits/stdc++.h>
using namespace std;

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int maxSum(int stack1[], int stack2[], int stack3[], int n1,
		int n2, int n3)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;

	// Finding the initial sum of stack1.
	for (int i = 0; i < n1; i++)
		sum1 += stack1[i];

	// Finding the initial sum of stack2.
	for (int i = 0; i < n2; i++)
		sum2 += stack2[i];

	// Finding the initial sum of stack3.
	for (int i = 0; i < n3; i++)
		sum3 += stack3[i];

	// As given in question, first element is top
	// of stack..
	int top1 = 0, top2 = 0, top3 = 0;
	while (1) {
		// If any stack is empty
		if (top1 == n1 || top2 == n2 || top3 == n3)
			return 0;

		// If sum of all three stack are equal.
		if (sum1 == sum2 && sum2 == sum3)
			return sum1;

		// Finding the stack with maximum sum and
		// removing its top element.
		if (sum1 >= sum2 && sum1 >= sum3)
			sum1 -= stack1[top1++];
		else if (sum2 >= sum1 && sum2 >= sum3)
			sum2 -= stack2[top2++];
		else if (sum3 >= sum2 && sum3 >= sum1)
			sum3 -= stack3[top3++];
	}
}

// Driven Program
int main()
{
	int stack1[] = { 3, 2, 1, 1, 1 };
	int stack2[] = { 4, 3, 2 };
	int stack3[] = { 1, 1, 4, 1 };

	int n1 = sizeof(stack1) / sizeof(stack1[0]);
	int n2 = sizeof(stack2) / sizeof(stack2[0]);
	int n3 = sizeof(stack3) / sizeof(stack3[0]);

	cout << maxSum(stack1, stack2, stack3, n1, n2, n3)
		<< endl;
	return 0;
}

/*

Output
5
Time Complexity : O(n1 + n2 + n3) where n1, n2 and n3 
    are sizes of three stacks.
*/

