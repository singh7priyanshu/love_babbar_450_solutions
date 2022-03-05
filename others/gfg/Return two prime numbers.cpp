/*
Return two prime numbers

Given an even number N (greater than 2), return two prime 
numbers whose sum will be equal to given number. There are 
several combinations possible. Print only the pair whose 
minimum value is the smallest among all the minimum values 
of pairs and print the minimum element first.

NOTE: A solution will always exist, read Goldbachs conjecture. 

Goldbach's conjecture is one of the oldest and best-known unsolved 
problems in number theory and all of mathematics. It states that 
every even whole number greater than 2 is the sum of two prime numbers.


Example 1:

Input: N = 74
Output: 3 71
Explaination: There are several possibilities 
like 37 37. But the minimum value of this pair 
is 3 which is smallest among all possible 
minimum values of all the pairs.
Example 2:

Input: 4
Output: 2 2
Explaination: This is the only possible 
prtitioning of 4.
Your Task:
You do not need to read input or print anything. Your task is to 
complete the function primeDivision() which takes N as input 
parameter and returns the partition satisfying the condition.

Expected Time Complexity: O(N*log(logN))
Expected Auxiliary Space: O(N)

Constraints:
4 ≤ N ≤ 104  
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> primeDivision(int N){
        // code here
        vector<bool> isprime(N+1, true);
        isprime[0]= false;
        isprime[1]=false;
        for(int i=2;i<=N;i++){
            if(!isprime[i]){
                continue;
            }
            if(i> N/i ){
                break;
            }
            for(int j=i*i;j<=N;j=j+i){
                isprime[j]= false;
            }
        }
        for(int i=2;i<=N;i++){
            if(isprime[i] && isprime[N-i]){
                vector<int>ans;
                ans.push_back(i);
                ans.push_back(N-i);
                return ans;
            }
        }
        vector<int>ans;
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        vector<int>ans = ob.primeDivision(n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}