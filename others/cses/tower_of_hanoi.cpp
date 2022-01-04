
/*
The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.

The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.

Your task is to find a solution that minimizes the number of moves.

Input

The only input line has an integer n: the number of disks.

Output

First print an integer k: the minimum number of moves.

After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.

Constraints
1≤n≤16
Example

Input:
2

Output:
3
1 2
1 3
2 3
*/


/*
//my try
#include<bits/stdc++.h>
using namespace std;

struct Stack{
	int capacity;
	int top;
	int *array;
};

struct Stack* createStack(int capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = (int*)malloc(stack -> capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack *stack){
	return(stack -> top == stack -> capacity -1 );
}

int isEmpty(struct Stack* stack){
	return (stack -> top == -1);
}

void push(struct Stack *stack , int item){
	if(isFull(stack)){
		return;
	}
	stack -> array[++stack -> top] = item;
}

int pop(struct Stack* stack){
	if(isEmpty(stack)){
		return INT_MIN;
	}
	return stack -> array[stack -> top--];
}

void moveDisk(char fromPeg, char toPeg , int disk){
	cout<<fromPeg<<" "<<toPeg<<"\n";
}

void moveDisksBetweenTwoPoles(struct Stack *src,struct Stack *dest, char s, char d){
	int pole1TopDisk = pop(src);
	int pole2TopDisk = pop(dest);

	if(pole1TopDisk == INT_MIN){
		push(src,pole2TopDisk);
		moveDisk(d,s,pole2TopDisk);
	}
	else if(pole2TopDisk == INT_MIN){
		push(dest,pole1TopDisk);
		moveDisk(s,d,pole1TopDisk);
	}
	else if(pole1TopDisk > pole2TopDisk){
		push(src, pole2TopDisk);
		push(src, pole1TopDisk);
		moveDisk(s,d, pole1TopDisk);
	}
}


void toh(int n, struct Stack *src, struct Stack *aux, struct Stack *dest){
	int i, total_num_of_moves;
	char s = '1', d = '3', a = '2';
	if(n%2 == 0){
		char temp = d;
		d=a;
		a=temp;
	}

	total_num_of_moves = pow(2, n)-1;
	cout<<total_num_of_moves<<"\n";

	for(i = n; i>=1; i--){
		push(src,i);
	}

	for(i=1; i<=total_num_of_moves;i++){
		if(i%3 == 1){
			moveDisksBetweenTwoPoles(src,dest,s,d);
		}
		else if(i%3 ==2){
			moveDisksBetweenTwoPoles(src,aux,s,a);
		}
		else if(i%3 == 0){
			moveDisksBetweenTwoPoles(aux,dest,a,d);
		}
	}

}

int main(){
	int n;
	cin>>n;
	struct Stack *src, *dest, *aux;

	src = createStack(n);
	aux = createStack(n);
	dest = createStack(n);
	
	toh(n,src,aux,dest);
	return 0;
}
*/

/*
Problem Name: Tower of Hanoi
Problem Link: https://cses.fi/problemset/task/2165
Author: Sachin Srivastava (mrsac7)
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(int a, int b, int c, int n) {
	if (n == 0)
		return;
	solve(a, c, b, n-1);
	cout<<a<<' '<<c<<endl;
	solve(b, a, c, n-1);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //#ifdef LOCAL
    //freopen("input.txt", "r" , stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    
    int n; cin>>n;
    cout<< (1<<n) - 1<<endl;

    solve(1, 2, 3, n);
}
