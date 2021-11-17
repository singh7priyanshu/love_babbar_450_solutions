
	class Solution:
		def minJumps(self, arr, n):
	    		#code here
	    		if len(arr) <= 1 : 
            			return 0 
  
        		# Return -1 if not possible to jump 
        		if arr[0] == 0 :  
            			return -1 
  
        		# initialization 
        		maxReach = arr[0]; 
        		step = arr[0]; 
       			jump = 1; 
  
  
        		# Start traversing array 
        		for i in range(1,len(arr)):

            			# Check if we have reached the end of the array 
            			if  i == len(arr) - 1 : 
                			return jump 
  
            			# updating maxReach 
           	 		maxReach = max(maxReach, i+arr[i])
  
            			# we use a step to get to the current index 
            			step-=1; 
  
            			# If no further steps left 
            			if  step == 0 : 
                			#  we must have used a jump 
                			jump+=1 
                   
                			#Check if the current index/position  or lesser index 
                			#is the maximum reach point from the previous indexes 
                			if i>=maxReach : 
                   				return -1
  
                			#re-initialize the steps to the amount 
                			#of steps to reach maxReach from position i. 
                			step = maxReach - i 
  
        		return -1

	if __name__=="__main__":
    		T = int(input())
    		for i in range(T):
        		n = int(input())
        		Arr = [int(x) for x in input().split()]
        		ob = Solution()
       	 		ans = ob.minJumps(Arr, n)
        		print(ans)  
