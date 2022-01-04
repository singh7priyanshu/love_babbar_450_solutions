
/*
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

Input

The first input line has an integer n: the number of apples.

The next line has n integers p1,p2,…,pn: the weight of each apple.

Output

Print one integer: the minimum difference between the weights of the groups.

Constraints
1≤n≤20
1≤pi≤109
Example

Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

/*

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	int n,p[20];
	cin>>n;
	ll s=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>p[i],s+=p[i];
	}
	for(int i=0;i<1<<n;++i){
		ll cs=0;
		for(int j=0;j<n;++j){
			if(i>>j&1){
				cs+=p[j];
			}
		}
		if(cs<=s/2){
			ans = max(ans,cs);
		}
	}
	cout<<s-2*ans;
}

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
int findminans(int *arr,int currsum,int totalsum,int i){
    if (i==0)
        return abs((totalsum-currsum) - currsum);

        return min(findminans(arr,currsum+arr[i],totalsum,i-1),findminans(arr,currsum,totalsum,i-1));

}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int *arr=new int[n];
    int totalsum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        totalsum+=arr[i];
    }

    cout<<findminans(arr,0,totalsum,n-1)<<endl;
return 0;
}