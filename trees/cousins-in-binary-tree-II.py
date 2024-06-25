"""
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # pre-process, sum of node values at each level of the tree
        level_sums = []

        q = deque()
        q.appendleft(root)

        while (q):
            size = len(q)
            level_sum = 0

            # each level
            while (size):
                curr = q.pop()
                level_sum += curr.val
                size -= 1

                if curr.left:
                    q.appendleft(curr.left)
                if curr.right:
                    q.appendleft(curr.right)
            level_sums.append(level_sum)
        
        # now we use level_sums to update each node's values accordingly
        q.appendleft(root)
        curr_level = 0
        root.val = 0

        while (q):
            size = len(q)

            # each level
            while (size):
                curr = q.pop()
                size -= 1

                if curr.left and curr.right:
                    left = curr.left.val
                    right = curr.right.val
                    curr.left.val = level_sums[curr_level + 1] - left - right
                    curr.right.val = level_sums[curr_level + 1] - left - right
                    q.appendleft(curr.left)
                    q.appendleft(curr.right)

                elif curr.left:
                    curr.left.val = level_sums[curr_level + 1] - curr.left.val
                    q.appendleft(curr.left)
                
                elif curr.right:
                    curr.right.val = level_sums[curr_level + 1] - curr.right.val
                    q.appendleft(curr.right)

            curr_level += 1
        
        return root


