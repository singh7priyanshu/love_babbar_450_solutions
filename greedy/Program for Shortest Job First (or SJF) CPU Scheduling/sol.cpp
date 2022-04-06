/*
Program for Shortest Job First (or SJF) CPU Scheduling

In operating systems that use paging for memory management, 
page replacement algorithm is needed to decide which page needs 
to be replaced when the new page comes in. Whenever a new page 
is referred and is not present in memory, the page fault occurs 
and Operating System replaces one of the existing pages with a 
newly needed page.

Given a sequence of pages in an array pages[] of length N and 
memory capacity C, find the number of page faults using 
Least Recently Used (LRU) Algorithm. 

Note:- Before solving this example revising the OS LRU cache 
mechanism is recommended.
https://www.geeksforgeeks.org/lru-cache-implementation/

We are given total possible page numbers that can be referred. 
We are also given cache (or memory) size (Number of page frames 
that cache can hold at a time). The LRU caching scheme is to 
remove the least recently used frame when the cache is full and 
a new page is referenced which is not there in cache. 


We use two data structures to implement an LRU Cache.  



Queue which is implemented using a doubly linked list. 
The maximum size of the queue will be equal to the total number of 
frames available (cache size). The most recently used pages will be 
near front end and least recently pages will be near the rear end.

A Hash with page number as key and address of the corresponding 
queue node as value.
When a page is referenced, the required page may be in the memory. 

If it is in the memory, we need to detach the node of the list 
and bring it to the front of the queue. 

If the required page is not in memory, we bring that in memory. 
In simple words, we add a new node to the front of the queue and 
update the corresponding node address in the hash. If the queue 
is full, i.e. all the frames are full, we remove a node from the 
rear of the queue, and add the new node to the front of the queue.

Example 1:

Input: N = 9, C = 4
pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}
Output: 8
Explaination: memory allocated with 4 pages 5, 0, 1, 
3: page fault = 4
page number 2 is required, replaces LRU 5: 
page fault = 4+1 = 5
page number 4 is required, replaces LRU 0: 
page fault = 5 + 1 = 6
page number 1 is required which is already present: 
page fault = 6 + 0 = 6
page number 0 is required which replaces LRU 3: 
page fault = 6 + 1 = 7
page number 5 is required which replaces LRU 2: 
page fault = 7 + 1  = 8.
Your Task:
You do not need to read input or print anything. Your task is to 
complete the function pageFaults() which takes N, C and pages[] as 
input parameters and returns the number of page faults.

Expected Time Complexity: O(N*C)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 1000
1 ≤ C ≤ 100
1 ≤ pages[i] ≤ 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_set<int> s;
    	unordered_map<int, int> indexes;
    
    	int page_faults = 0;
    	for (int i = 0;i < N; i++){
    		if (s.size() < C){
    			if (s.find(pages[i]) == s.end()){
    				s.insert(pages[i]);
    				page_faults++;
    			}
    			indexes[pages[i]] = i;
    		}
    		else{
    			if (s.find(pages[i]) == s.end()){
    				int lru = INT_MAX, val;
    				for (auto it = s.begin();it != s.end(); it++){
    					if (indexes[*it] < lru){
    						lru = indexes[*it];
    						val = *it;
    					}
    				}
    				s.erase(val);
    				s.insert(pages[i]);
    				page_faults++;
    			}
    			indexes[pages[i]] = i;
    		}
    	}
    	return page_faults;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, c;
        cin>>n;
        int pages[n];
        for(int i = 0;i<n;i++)cin>>pages[i];
        cin>>c;
        Solution ob;
        cout<<ob.pageFaults(n, c, pages)<<endl;
    }
    return 0;
}
