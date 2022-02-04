/*
Find whether an array is a subset of another array

Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
 

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:

Input:
a1[] = {1, 2, 3, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 3:

Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
Explanation:
a2[] is not a subset of a1[]
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubset() which takes the array a1[], a2[], its size n and m as inputs and return "Yes" if arr2 is subset of arr1 else return "No" if arr2 is not subset of arr1.

 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


Constraints:
1 <= n,m <= 105
1 <= a1[i], a2[j] <= 105

*/

#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m);

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int a1[n], a2[m];
        for(int i = 0;i<n;i++)cin>>a1[i];
        for(int i = 0;i<m;i++)cin>>a2[i];
        cout<<isSubset(a1,a2,n,m)<<endl;
    }
    return 0;
}

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int>um, um2;
    for(int i = 0;i<n;i++)um[a1[i]]++;
    for(int i = 0;i<m;i++)um2[a2[i]]++;
    int count = 0;
    for(auto it = um2.begin(); it != um2.end(); it++){
        if(um[it->first] >= it->second){
            count++;
        }
    }
    if (count == m)return "Yes";
    else return "No";
}