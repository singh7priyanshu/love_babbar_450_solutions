/*
1345. Jump Game IV

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the 
last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 

Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108

*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , vector<int>> StoreIndex;
        unordered_map<int , int>DoneElement;
        
        for(int index = 0; index < arr.size(); index++){
            StoreIndex[arr[index]].push_back(index); 
            DoneElement[arr[index]] = 1; 
        }
        
        
        vector<bool>visited(n , false);
        vector<int>parent(n , 0);
        queue<int>openList;
        openList.push(0);
        visited[0] = true;
        
        while(!openList.empty()){
            auto topElement = openList.front();
            openList.pop();
            if(topElement == arr.size() - 1) return parent[topElement];
            
            if((topElement + 1) < n && !visited[topElement + 1]){
                openList.push(topElement + 1);
                parent[topElement + 1] = 1+ parent[topElement];
                visited[topElement + 1] = true;
            }
            if((topElement - 1) >= 0 && !visited[topElement - 1]){
                openList.push(topElement - 1);
                parent[topElement - 1] = 1 + parent[topElement];
                visited[topElement - 1] = true;
            }
            if(DoneElement[arr[topElement]] == 1){
                for(auto equalValIndex : StoreIndex[arr[topElement]]){
                    if(!visited[equalValIndex] && equalValIndex != topElement){
                        if(equalValIndex == n-1) return parent[topElement] + 1;
                        
                        openList.push(equalValIndex);
                        parent[equalValIndex] = 1  + parent[topElement];
                        visited[equalValIndex] = true;
                    }
                }
                DoneElement[arr[topElement]] = 0;
            }
        }
        
        return -1;
    }
};