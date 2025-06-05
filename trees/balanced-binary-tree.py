# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        balancedFlag = True


        def checkHeight(root: Optional[TreeNode]) -> int:
            nonlocal balancedFlag
            
            if not root:
                return 0
            
            left = checkHeight(root.left)
            right = checkHeight(root.right)

            if (abs(left - right) > 1):
                balancedFlag = False
                return -1

            return 1 + max(left, right)


        checkHeight(root)
        return False if not balancedFlag else True
