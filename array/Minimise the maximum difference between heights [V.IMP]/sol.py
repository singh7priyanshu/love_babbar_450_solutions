
	class Solution:
    		def getMinDiff(self, arr, n, k):
        		# code here
        		v = []
        		taken = [0]*n
        
        		for i in range(n):
            			if arr[i]-k >= 0:
                			v.append([arr[i]-k,i])
            			v.append([arr[i] + k,i])
           		v.sort()
        
        		elements_in_range = 0;
        		left = 0
        		right = 0
        
        		while elements_in_range < n and right < len(v) :
            
            			if taken[v[right][1]] == 0 :
                			elements_in_range+=1;
            
            			taken[v[right][1]]+=1;
            			right+=1;
        
        
        		ans = v[right - 1][0] - v[left][0]
        
        		while right < len(v) :
    
            			if(taken[v[left][1]] == 1) :
               				elements_in_range-=1;
            
            			taken[v[left][1]]-=1;
           			left+=1
            
            			while elements_in_range < n and right < len(v) : 
                			if taken[v[right][1]] == 0 :
                    				elements_in_range+=1
                
                			taken[v[right][1]]+=1
                			right+=1
            
            
            			if(elements_in_range == n) : 
                			ans = min(ans, v[right - 1][0] - v[left][0])
            			else :
                			break
            		return ans
	
	if __name__=="__main__":
    		tc =  int(input())
    		while tc > 0:
        		k = int(input())
        		n = int(input())
        		arr = list(map(int, input().strip().split()))
        		ob = Solution()
        		ans = ob.getMinDiff(arr, n ,k)
        		print(ans)
        		tc-=1   