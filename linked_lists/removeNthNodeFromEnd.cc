/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
        // get pointer to nth from end
        // use two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        if (!head->next) return nullptr;

        while (n--) {
            fast = fast->next;
        }

        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // prev pointer should be pointing to the Listnode behind the one being removed
        if (!prev) {
            // then remmove head
            head = head->next;
        } else {
            prev->next = prev->next->next;
        }
        return head;
    }
};
