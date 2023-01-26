// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * merged = new ListNode{}; // dummy node
        ListNode * tmp = merged;
        ListNode * p1 = list1;
        ListNode * p2 = list2;

        while (p1 && p2) {
            if (p1->val > p2->val) {
                tmp->next = new ListNode{p2->val, nullptr};
                p2 = p2->next;
            } else {
                tmp->next = new ListNode{p1->val, nullptr};
                p1 = p1->next; 
            } 
            tmp = tmp->next;
        }

        while(p1) {
            tmp->next = new ListNode{p1->val, nullptr};
            p1 = p1->next;
            tmp = tmp->next;
        }

        while(p2) {
            tmp->next = new ListNode{p2->val, nullptr};
            p2 = p2->next;
            tmp = tmp->next;
        }

        return merged->next;
    }
};
