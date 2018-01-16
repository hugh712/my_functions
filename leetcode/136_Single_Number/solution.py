class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
	dic={}
	for ii in nums:
		if ii in dic:
			dic[ii]=dic[ii]+1
		else:
			dic[ii]=1

	for jj in dic:
		if dic[jj]==1:
			return jj
		

aa=[1,1,2,2,3,3,4,5,5]
ins=Solution()
output=ins.singleNumber(aa)
print output
