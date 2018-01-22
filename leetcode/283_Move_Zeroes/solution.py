class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
 	p1=0
	p2=len(nums)-1
	while p1 < p2:
		if nums[p1] == 0:
			for i in xrange(p1, p2):
				temp=nums[i]
				nums[i]=nums[i+1]
				nums[i+1]=temp
			p2=p2-1
                if nums[p1]!=0:
                    p1=p1+1

nums = [0,0,1]
ss=Solution()
ss.moveZeroes(nums) 
print nums
