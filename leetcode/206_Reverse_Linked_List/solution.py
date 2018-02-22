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
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

	if head==None:
		return head
	
	curr=head
	L2=None

	while curr!=None:
		temp=ListNode(curr.val)
		temp.next=L2
		L2=temp
		curr=curr.next

	return L2		

aa=[1,2,3,4,5,6]
L1=createNodes(aa)
visitNodes(L1)
ss=Solution()
L2=ss.reverseList(L1)
visitNodes(L2)
