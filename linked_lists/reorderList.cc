/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed
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
    void reorderList(ListNode* head) {
        // add to stack
        stack<ListNode*> s;
        int length = 0;

        ListNode* p = head;
        while (p) {
            s.push(p);
            length += 1;
            p = p->next;
        }

        // if list is length 1 or 0, simply return
        if (length == 0 || length == 1) return;

        // change list
        int boundary = length / 2;
        p = head;
        while (boundary != 0) {
            ListNode* tmp = s.top();
            s.pop();

            tmp->next = p->next;
            p->next = tmp;
            p = p->next->next;
            boundary -= 1;
        }

        p->next = nullptr;
    }
};
