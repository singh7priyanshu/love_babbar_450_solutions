	class Solution(object):
    		def findDuplicate(self, nums):
        		"""
        		:type nums: List[int]
        		:rtype: int
        		"""
        		if len(nums) > 1:
           	 		slow = nums[0]
            			fast = nums[nums[0]]
            			while slow != fast:
                			slow = nums[slow]
                			fast = nums[nums[fast]]
            			fast = 0
            			while slow != fast:
                			slow = nums[slow]
                			fast = nums[fast]
            			return slow
        
        		return -1