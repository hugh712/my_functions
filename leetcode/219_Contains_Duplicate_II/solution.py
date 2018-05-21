class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        hex={}
        for i, num in enumerate(nums):
            if num in hex and i-hex[num]<=k:
                return True
            hex[num]=i

        return False

Arr=[1,2,3,1]
k=3
ss=Solution()
rr=ss.containsNearbyDuplicate(Arr,3)
print("result=%s" % rr)
