class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max=0
        isZero=0
        sum_miss=sum(nums)
        sum_full=0

        for i in nums:
            if i >= max:
                max=i

            if i==0:
                isZero=1
            
        sum_full=sum(range(0,max+1))

        diff=sum_full-sum_miss

        if diff==0:
            if isZero:
                diff=max+1
            else:
                diff=0

        return diff

        
nn=[0]
#nn=[1]
#nn=[0,1]
#nn=[1,2]
#nn=[9,6,4,2,3,5,7,0,1]
ss=Solution()
rr=ss.missingNumber(nn)
print(rr)
