/**
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
  
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // empty linked list
        if (!head) return head;
        // linked list with one node
        if (!head->next) return head;

        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *prev = dummyHead;
        ListNode *curr = head;

        while ( curr && curr->next ) {
            ListNode *nxt = curr->next->next;
            ListNode *second = curr->next;

            second->next = curr;
            curr->next = nxt;
            prev->next = second;

            prev = curr;
            curr = nxt;
            
        }


        return dummyHead->next;
    }
};
