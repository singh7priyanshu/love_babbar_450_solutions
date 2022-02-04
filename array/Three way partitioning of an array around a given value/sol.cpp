/*
Three way partitioning of an array around a given value

Three way partitioning

Given an array of size n and a range [a, b]. The task is to partition the array 
around the range such that array is divided into three parts.

1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.

The individual elements of three sets can appear in any order. 
You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input: 
n = 3 
A[] = {1, 2, 3}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement 
is: {1, 2, 3}. If you return a valid
arrangement, output will be 1.


Your Task:
You dont need to read input or print anything. The task is to complete the function 
threeWayPartition() which takes the array[], a and b as input parameters and modifies the 
array in-place according to the given conditions.

Note: The generated output is 1 if you modify the given array successfully.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
1 <= n <= 106
1 <= A[i] <= 106

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b){
        int start = 0, end = array.size()-1;
        for(int i = 0;i<=end;){
            if(array[i]<a)swap(&array[i++], &array[start++]);
            else if(array[i]>b)swap(&array[i], &array[end--]);
            else i++;
        }
    }
    void swap(int *xp, int *yp){
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>array(N);
        unordered_map<int,int>ump;
        for(int i = 0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        int a, b;
        cin>>a>>b;
        vector<int>original = array;
        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0, kk2 = 0, kk3 = 0;
        for(int i = 0;i<N;i++){
            if(original[i]>b)k3++;
            else if(original[i]<=b && original[i]>=a)k2++;
            else if(original[i]<b)k1++;
        }
        Solution ob;
        ob.threeWayPartition(array, a, b);

        for(int i = 0;i<k1;i++){
            if(array[i]<b)kk1++;
        }
        for(int i = k1;i<k1+k2;i++){
            if(array[i]<=b && array[i]>=a)kk2++;
        }
        for(int i = k1+k2;i<k1+k2+k3;i++){
            if(array[i]>b)kk3++;
        }
        bool ok = 0;
        if(k1==kk1 && k2 == kk2 && k3 ==kk3)ok = 1;
        for(int i = 0;i<array.size();i++)ump[array[i]]--;
        for(int i = 0;i<array.size();i++){
            if(ump[array[i]]!=0)ok = 0;
        }
        if(ok)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
