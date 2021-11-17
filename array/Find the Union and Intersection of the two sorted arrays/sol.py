
	class Solution:    
    		#Function to return the count of number of elements in union of two arrays.
    		def doUnion(self,a,n,b,m):
        
        		#code here
        		#using set to store the elements.
        		hs=set() 
        
        		#we insert all the elements of first array in set.
        		for i in range(0,n): 
            			hs.add(a[i]) 
        
        		#we insert all the elements of second array in set.
    			#Set does not contain duplicates.
        		for i in range(0,m): 
            			hs.add(b[i]) 
        
        		#returning the size of set which is total number of elements in set.
        		return len(hs)

	#driver code 
	if __name__=='__main__':
  		t= int(input())
    		for _ in range(t):
        		n,m = [int(x) for x in input().strip().split()]
        		a = [int(x) for x in input().strip().split()]
        		b = [int(x) for x in input().strip().split()]
        		ob =  Solution()
        		print (ob.doUnion(a,n,b,m))
			