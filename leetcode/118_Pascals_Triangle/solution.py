#!/usr/bin/env python3
#! -*- coding=utf-8 -*-

class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        output=[]
        if numRows==0:
            return []
        if numRows>=1:
            temp=[1]
            output.append(temp)
        if numRows>=2:
            temp=[1,1]
            output.append(temp)
        if numRows<=2:
            return output
        last=1
        for i in range(2, numRows):
            temp=[1]

            for j in range(1,i):
                temp.append(output[last][j-1]+output[last][j])
            temp.append(1)
            output.append(temp)
            last+=1
        return output


ss=Solution()
rr=ss.generate(5)
print(rr)
