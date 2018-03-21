#!/usr/bin/env python3
# -*- cording=utf-t -*-

import pdb

class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        last=[]
        curr=[]
        if rowIndex<=0:
            last.append(1)
        else:
            last=[1,1]

        if rowIndex<=1:
            return last
        for i in range(2,rowIndex+1):
            curr=[1]
            for j in range(1, i):
                curr.append(last[j-1]+last[j])
            curr.append(1)
            last=curr
        return curr


ss=Solution()
rr=ss.getRow(2)
print(rr)
