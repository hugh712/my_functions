class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dic={}
        for value in nums:
            if value in dic:
                dic[value]=dic[value]+1
            else:
                dic[value]=1

        for value in dic.values():
            if value>1:
                return True

        return False
a=Solution()
arr=[1,2,3,4,5,6,6]
a.containsDuplicate(arr)
