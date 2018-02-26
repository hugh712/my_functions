import math
class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """

	if (num<=0):
		return False

	return num==math.pow(4,math.floor(math.log(num+1)/math.log(4))) 

ss=Solution()
rr=ss.isPowerOfFour(63)
print('retult=', rr)
