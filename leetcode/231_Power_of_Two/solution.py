import pdb

class Solution:
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """

        if n<=0:
            return False
        if n==1:
            return True
        while n>=1:
            if n%2 is not 0:
                return False
            n=int(n/2)
            
            if n<2:
                return True
        return True

ss=Solution()
rr=ss.isPowerOfTwo(16)
print(rr)
