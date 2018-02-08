# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):


def isBadVersion(version):
    if version >=49:
        return True
    else:
        return False
class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            if isBadVersion(1):
                return 1
            else:
                return -1

        p1=0
        p2=n
        middle=(int)((p2-p1)/2)

        while((p2-p1)>1):
            if(not isBadVersion(middle)):
                p1=middle
            else:
                if not isBadVersion(middle-1):
                    return middle
                p2=middle
        
            middle=p1+(int)((p2-p1)/2)

        #for last one
        if isBadVersion(middle):
            return middle
        elif isBadVersion(n):
            return n
        else:
            return -1

ss=Solution()
rr=ss.firstBadVersion(50)
print(rr)
