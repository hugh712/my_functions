# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def BSTHelper(self, root, leftB,rightB):
	if root == None:
		return True
	if leftB is not None and leftB >= root.val:
		return False
	if rightB is not None and rightB <= root.val:
		return False
	return self.BSTHelper(root.left,leftB, root.val ) and self.BSTHelper(root.right, root.val, rightB)  
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
	return self.BSTHelper(root,None,None)

node=TreeNode(2)
ss=Solution()
ss.isValidBST(node)
