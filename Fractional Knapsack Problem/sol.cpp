/*
Fractional Knapsack Problem

Given weights and values of N items, we need to put these 
items in a knapsack of capacity W to get the maximum total 
value in the knapsack.

Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
 

Your Task :
Complete the function fractionalKnapsack() that receives 
maximum capacity , array of structure/class and size n and 
returns a double value representing the maximum value in 
knapsack.

Note: The details of structure/class is defined in the 
comments above the given function.


Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= W <= 105
*/

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution{
    public: 
    static bool cmp(Item a, Item b)
    {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    
    
    public:
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr + n, cmp);
        int curWeight = 0;
        double finalvalue = 0.0;
        for (int i = 0; i < n; i++){
            if (curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else{
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double) remain / arr[i].weight);
                break;
            }
        }
        return finalvalue;
    }
};

int main(){
    int t; cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--){
        int n, W;
        cin>>n>>W;
        Item arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i].value>>arr[i].weight;
        Solution ob;
        cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
}