class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
	dic={}
	retArr=[]
	for ii in nums1:
		if ii in dic:
			dic[ii]=dic[ii]+1
		else:
			dic[ii]=1

	for jj in nums2:
		if jj in dic and dic[jj]!=0:
			retArr.append(jj)
			dic[jj]=dic[jj]-1
	return retArr
ss=Solution()
aa=[1,2,2,1,2,3]
bb=[3,2,2]
cc=ss.intersect(aa,bb)
print cc
