class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ll=[]
        for i in range(1,n+1):
            if i%3==0 and i%5==0:
                ll.append("FizzBuzz")
            elif i%3==0:
                ll.append("Fizz")
            elif i%5==0:
                ll.append("Buzz")
            else:
                ll.append(str(i))
        return ll
n=10
ss=Solution()
rr=ss.fizzBuzz(n)
print(rr)
