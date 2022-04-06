/*
Program for Shortest Job First (or SJF) CPU Scheduling

Shortest job first (SJF) or shortest job next, 
is a scheduling policy that selects the waiting 
process with the smallest execution time to execute next. 

SJN, also known as Shortest Job Next (SJN), 
is a non-preemptive algorithm. 
 

Shortest Job first has the advantage of having a minimum 
average waiting time among all scheduling algorithms.

It is a Greedy Algorithm.
It may cause starvation if shorter processes keep coming. 
This problem can be solved using the concept of ageing.
It is practically infeasible as Operating System may not 
know burst time and therefore may not sort them. 
While it is not possible to predict execution time, 
several methods can be used to estimate the execution 
time for a job, such as a weighted average of previous 
execution times. 

SJF can be used in specialized environments where accurate 
estimates of running time are available.

Algorithm: 

Sort all the process according to the arrival time. 
 
Then select that process which has minimum arrival 
    time and minimum Burst time. 
 
After completion of process make a pool of process 
    which after till the completion of previous process 
    and select that process among the pool which is 
    having minimum Burst time. 

How to compute below times in SJF using a program? 
 

Completion Time: Time at which process completes its 
execution.

Turn Around Time: Time Difference between completion time 
    and arrival time. 
    Turn Around Time = Completion Time – Arrival Time

Waiting Time(W.T): Time Difference between turn around time 
    and burst time. 
    Waiting Time = Turn Around Time – Burst Time

In this post, we have assumed arrival times as 0, 
so turn around and completion times are same.

*/

// C++ program to implement Shortest Job first with Arrival
// Time
#include <iostream>
using namespace std;
int mat[10][6];

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mat[j][1] > mat[j + 1][1]) {
				for (int k = 0; k < 5; k++) {
					swap(mat[j][k], mat[j + 1][k]);
				}
			}
		}
	}
}

void completionTime(int num, int mat[][6])
{
	int temp, val;
	mat[0][3] = mat[0][1] + mat[0][2];
	mat[0][5] = mat[0][3] - mat[0][1];
	mat[0][4] = mat[0][5] - mat[0][2];

	for (int i = 1; i < num; i++) {
		temp = mat[i - 1][3];
		int low = mat[i][2];
		for (int j = i; j < num; j++) {
			if (temp >= mat[j][1] && low >= mat[j][2]) {
				low = mat[j][2];
				val = j;
			}
		}
		mat[val][3] = temp + mat[val][2];
		mat[val][5] = mat[val][3] - mat[val][1];
		mat[val][4] = mat[val][5] - mat[val][2];
		for (int k = 0; k < 6; k++) {
			swap(mat[val][k], mat[i][k]);
		}
	}
}

int main()
{
	int num, temp;

	cout << "Enter number of Process: ";
	cin >> num;

	cout << "...Enter the process ID...\n";
	for (int i = 0; i < num; i++) {
		cout << "...Process " << i + 1 << "...\n";
		cout << "Enter Process Id: ";
		cin >> mat[i][0];
		cout << "Enter Arrival Time: ";
		cin >> mat[i][1];
		cout << "Enter Burst Time: ";
		cin >> mat[i][2];
	}

	cout << "Before Arrange...\n";
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\n";
	}

	arrangeArrival(num, mat);
	completionTime(num, mat);
	cout << "Final Result...\n";
	cout << "Process ID\tArrival Time\tBurst Time\tWaiting "
			"Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\t\t" << mat[i][4] << "\t\t"
			<< mat[i][5] << "\n";
	}
}

/*

Output
Enter number of Process: ...Enter the process ID...
Before Arrange...
Process ID    Arrival Time    Burst Time
Final Result...
Process ID    Arrival Time    Burst Time    Waiting Time    Turnaround Time

Output:

Process ID      Arrival Time    Burst Time
1               2               3
2               0               4
3               4               2
4               5               4
Final Result...
Process ID      Arrival Time    Burst Time      Waiting Time    Turnaround Time
2               0               4               0               4
3               4               2               0               2
1               2               3               4               7
4               5               4               4               8

*/