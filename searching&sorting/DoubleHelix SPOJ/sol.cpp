/*
DoubleHelix SPOJ

ANARC05B - The Double HeLiX
#dynamic-programming #binary-search

Two ﬁnite, strictly increasing, integer sequences are given. Any common 
integer between the two sequences constitute an intersection point. 
Take for example the following two sequences where intersection points are
printed in bold:

First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. 
Now start moving forward.
At each intersection point, you have the choice of either continuing 
with the same sequence you’re currently on, or switching to the other sequence.

The objective is ﬁnding a path that produces the maximum sum of data 
you walked over. In the above example, the largest possible sum is 450,
which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input
Your program will be tested on a number of test cases. Each test case will 
be speciﬁed on two separate lines. Each line denotes a sequence and is 
speciﬁed using the following format:

n v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. 
Each sequence will have at least one element but no more than 10,000. All elements 
are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.

Output
For each test case, write on a separate line, the largest possible sum that can be produced.

Sample
Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

Output:
450
2100

*/

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

int a[11000], b[11000];

int max(int c, int d) {
    return c > d ? c : d;
}

int main(int argc, char * argv[]) {

    int n, m;
    scanf("%d" , &n);

    while (n != 0) {

        for (int i = 0; i < n; i++)
            scanf("%d" , &a[i]);

        scanf("%d" , &m);
        for (int i = 0; i < m; i++)
            scanf("%d" , &b[i]);

        int suma = 0, sumb = 0, result = 0;
        int i = 0, j = 0;

        while (1) {

            if (i < n && j < m && a[i] < b[j]) {
                suma += a[i];
                //cout << "suma = " << suma << endl;
                i++;
            } else if (i < n && j < m && b[j] < a[i]) {
                sumb += b[j];
                //cout << "sumb = " << sumb << endl;
                j++;
            } else if (i < n && j < m && a[i] == b[j]) {
                result += max(suma + a[i], sumb + b[j]);
                //cout << "result = " << result << endl;
                suma = sumb = 0;
                i++;
                j++;
            }

            if ( i >= n && j >= m )
                break;

            if ( i >= n ) {
                //cout << "adding remaining b" << endl;
                while ( j < m ) {
                    sumb += b[j];
                    j++;
                }
                result += max(suma , sumb);
                break;
            }

            if ( j >= m ) {
                //cout << "adding remaining a" << endl;
                while ( i < n ) {
                    suma += a[i];
                    //cout << "suma = " << suma << endl;
                    i++;
                }
                //cout << " max of : " << suma << " and " << sumb << endl;
                result += max(suma, sumb);
                //cout << "result = " << result << endl;
                break;
            }

        }

        cout << result << endl;

        scanf("%d" , &n);
    }

    return 0;
}