# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

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

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if head==None or head.next==None:
            return False

        dic={}		
        while head!=None:
            if head in dic:
                return True
            dic[head]=1
            head=head.next
        return False


arr=[1,2,3,3,2,1,4,4,4,4]
L1=createNodes(arr)
visitNodes(L1)
ss=Solution()
rr=ss.hasCycle(L1)
print(rr)
