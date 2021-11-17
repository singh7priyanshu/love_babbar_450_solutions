
	class Solution:
    		def nextGap(self,gap):
        
        		#It returns the ceil value of gap/2 or 0 if gap is 1.
        		if(gap<=1):
            			return 0
        		return ((gap+1)//2)
        
    		def merge(self, arr1, arr2, n, m): 
        		# code here
        		gap=n+m
        		gap = self.nextGap(gap)
        		while(gap>0):
            			i=0
            
            			#Comparing elements in the first array itself with difference in 
    	    			#index equal to the value of gap.
            			while(i+gap<n):
                
                			#If element at ith index is greater than element at
    		    			#(i+gap)th index, we swap them.
                			if(arr1[i]>arr1[i+gap]):
                    				arr1[i],arr1[i+gap]=arr1[i+gap],arr1[i]
                			i+=1
    
            			j = max(0, gap - n)
            
            			#Now comparing elements in both arrays with help of two pointers.
    				#The loop stops whenever any pointer exceeds the size of its array.
            			while(i<n and j<m):
                
                			#If element in the first array is greater than element in
    		    			#second array, we swap them.
                			if(arr1[i]>arr2[j]):
                    				arr1[i],arr2[j]=arr2[j],arr1[i]
                			i+=1
                			j+=1
        
            			if(j<m):
                			j=0
                
                			#At last, comparing elements in the second array itself with 
                			#difference in index equal to the value of gap.
                			while(j+gap < m):
                    
                    				#If element at jth index is greater than element at
    		        			#(j+gap)th index, we swap them.
                    				if (arr2[j] > arr2[j + gap]):
                        				arr2[j], arr2[j + gap] = arr2[j + gap], arr2[j]
                    				j+=1
                    
            			#Updating the value of gap.        
            			gap = self.nextGap(gap)
				
	if __name__ == "__main__":
		tc = int(input())
		while tc > 0:
			n, m = map(int ,(input().strip().split()))
			arr1 = list(map(int, input().strip().split()))
			arr2 = list(map(int, input().strip().split()))
			ob = Solution()
			ans = ob.merge(arr1, arr2, n, m)
			for x in arr1:
				print(x, end = " ")
			for x in arr2:
				print(x, end = " ")
			print()
			tc = tc-1