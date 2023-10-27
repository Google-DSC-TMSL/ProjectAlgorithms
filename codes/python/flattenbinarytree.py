# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def preorder(current):
            if current==None:
                return None

            leftn=preorder(current.left)
            rightn=preorder(current.right)
            
            if current.left!=None:
                temp=current.right
                current.right=current.left
                current.left=None
                leftn.right=temp

            if rightn!=None:
                return rightn
            
            if leftn!=None:
                return leftn
            
            return current
        preorder(root)
            

            
            
            
            

        