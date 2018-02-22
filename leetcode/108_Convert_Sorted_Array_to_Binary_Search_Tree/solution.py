# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def insertBST(self,nums,start,end):
	if (start > end):
		return None
	
	mid=(int)((start+end)/2)
	curr=TreeNode(nums[mid])
	curr.left=self.insertBST(nums,start,mid-1)
	curr.right=self.insertBST(nums,mid+1,end)

	return curr			
    def sortedArrayToBST(self,nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
	return self.insertBST(nums,0,len(nums)-1)

arr=[-33,-10,-3,-1,0,5,9,11,15]
ss=Solution()
rr=ss.sortedArrayToBST(arr)
