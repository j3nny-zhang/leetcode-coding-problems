// Given the head of a linked list, rotate the list to the right by k places.

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;

        if (head == NULL) return NULL;
        
        // get length and put pointer at end of the list
        ListNode *end = head;
        while (end->next) {
            end = end->next;
            length += 1;
        }
        length += 1; // add one because we want num of nodes (not links, which is num of iterations in while loop)
        
        ListNode *curr = head;
        k = k % length; // guarentees k < length


        // here we want iterations = num of links, so start at i = 1
        // put curr pointer before the new head of the rotated linked list
        int i = 1;
        while (i < length - k) {
            curr = curr->next;
            i += 1;
        }

        end->next = head;
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};
