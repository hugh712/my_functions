class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
		return 0
	a=0
	b=0

	for ii in range(0,len(nums)):
		if ii%2==0:
                    a=max(a+nums[ii],b)				
		else:
                    b=max(a,nums[ii]+b)

        return max(a,b)

Arr=[2,1,1,2]
ss=Solution()
rr=ss.rob(Arr)
print(rr)
