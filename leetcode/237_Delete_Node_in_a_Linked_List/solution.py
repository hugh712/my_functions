# Definition for singly-linked list.
# class ListNode(object):
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
    print cur.val
    while cur.next:
        cur=cur.next
        print cur.val

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next

Arr=[3,1,2,4,7]
node=createNodes(Arr)
ss=Solution()
visitNodes(node)
curr=node.next.next
ss.deleteNode(curr)
print "\n\n"
visitNodes(node)
