'''
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
 
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merged = ListNode()
        head = merged
        
        p1 = list1
        p2 = list2

        while p1 and p2:
            if p1 and p2:
                if p1.val < p2.val:
                    merged.next = ListNode(p1.val)
                    p1 = p1.next
                else:
                    merged.next = ListNode(p2.val)
                    p2 = p2.next
                
                merged = merged.next
                
        while p1:
            merged.next = ListNode(p1.val)
            merged = merged.next
            p1 = p1.next
                
        while p2:
            merged.next = ListNode(p2.val)
            merged = merged.next
            p2 = p2.next
        
        return head.next
