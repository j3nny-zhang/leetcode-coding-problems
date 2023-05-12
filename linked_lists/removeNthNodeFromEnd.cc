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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *prev = head;
      ListNode *a = head;
      ListNode *b = head;

      if (!head->next) {
        return nullptr;
      } 

      for (int i = 0; i < n; i++) {
        b = b-> next;
      }

      while (b) {
        prev = a;
        a = a->next;
        b = b->next;
      }

      if (a) cout << a->val << " : ";
      if (b) cout << b->val << endl;
      cout << prev->val << endl;

      if (prev == a) {
        head = head->next;
        delete prev;
      } else {
        prev->next = a->next;
        delete a;
      }

      return head;
    }
};
