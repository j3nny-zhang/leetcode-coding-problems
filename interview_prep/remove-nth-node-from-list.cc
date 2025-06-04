/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fast = head;

        while (n--) fast = fast->next;

        while (fast) {
            prev = curr;
            curr = curr->next;
            fast = fast->next;
        }

        if (prev) {
            prev->next = curr->next;
        } else {
            return head->next;
        }

        return head;
    }
};
