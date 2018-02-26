#/usr/bin/env python3
# -*- coding=utf-8 -*-

import math
class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """

        if n<0:
            return False

        return  n==math.pow(3,math.floor(math.log(n+1)/math.log(3)))
	

ss=Solution()
rr=ss.isPowerOfThree(244)
print('result=',rr)
