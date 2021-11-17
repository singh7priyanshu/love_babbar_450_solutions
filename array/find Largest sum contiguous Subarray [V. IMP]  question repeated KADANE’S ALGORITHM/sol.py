
	class Solution:
   	 	##Complete this function
    		#Function to find the sum of contiguous subarray with maximum sum.
    		def maxSubArraySum(self,arr,N):
        		##Your code here
        		max_so_far = -9999999 - 1
        		max_ending_here = 0
        
        		#Iterating over the array. 
        		for i in range(0, N): 
            			#Updating max sum till current index.
            			max_ending_here = max_ending_here + arr[i]
            
            			#Storing max sum so far by choosing maximum between max 
            			#sum so far and max sum till current index.
            			if (max_so_far < max_ending_here): 
                			max_so_far = max_ending_here 
        
            			#If max sum till current index is negative, we do not need to add
            			#it to result so we update it to zero.
            			if max_ending_here < 0: 
                			max_ending_here = 0   
        
        		#returning the result.
        		return max_so_far

	import math

	def main():
    		T = int(input())
    		while(T>0):
        		n = int(input())
        		arr = [int(x) for x in input().strip().split()]
        		ob = Solution
        		print(ob.maxSubArraySum(arr,n))
        		T-=1

	if __name__ == "__main__":
    		main()
