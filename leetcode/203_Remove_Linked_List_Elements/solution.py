class ListNode(object):
    def __init__(self, x): 
        self.val=x
        self.next=None

def createNodes(Arr):
    L1=ListNode(Arr[0])
    cu=L1
    for i in Arr[1:]:
        cu.next=ListNode(i)
        cu=cu.next

    return L1
def visitNodes(Head):
    cur=Head
    print(cur.val)
    while cur.next:
        cur=cur.next
        print(cur.val)

class Solution:
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head is None:
            return None
        
        prev=None
        curr=head
        tmp=None

        while curr!=None:
            if curr.val==val:
                tmp=curr

                if prev!=None:
                    prev.next=curr.next
                else:
                    head=curr.next

                curr=curr.next
            else:
                prev=curr
                curr=curr.next

        return head







arr=[1,2,3,4,5,6,4,5,6]
L1=createNodes(arr)
visitNodes(L1)
ss=Solution()
rr=ss.removeElements(L1,6)
print("-------------------")
visitNodes(rr)
