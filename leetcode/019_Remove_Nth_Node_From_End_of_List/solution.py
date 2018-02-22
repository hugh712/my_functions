# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def createNodes(Arr):
    L1=ListNode(Arr[0])
    cu=L1
    for i in Arr[1:]:
        cu.next=ListNode(i)
        cu=cu.next

    return L1
def visitNodes(Head):
    cur=Head
    print cur.val
    while cur.next:
        cur=cur.next
        print cur.val

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
	first=head
	second=head

	while first :
	    first=first.next
            if n<0:
                second=second.next
	    n-=1	

        if n==0:
            head=head.next
        else:
            second.next=second.next.next

        return head

		


Arr=[3,1,2,4,7]
node=createNodes(Arr)
visitNodes(node)
ss=Solution()
rr=ss.removeNthFromEnd(node,5)
print "\n"
visitNodes(rr)
