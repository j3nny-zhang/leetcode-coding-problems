#include <iostream>
#include <vector>

// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = nullptr;
        std::vector<int> sums = {};

        auto *p1 = l1;
        auto *p2 = l2;

        while (p1 != nullptr || p2 != nullptr) {
            int sum; 
            
            if (p1 != nullptr && p2 != nullptr) {
                sum = p1->val + p2->val;
            } else if (p1 != nullptr && p2 == nullptr) {
                sum = p1->val;
            } else if (p1 == nullptr && p2 != nullptr) {
                sum = p2->val;
            }
            
            sums.push_back(sum);

            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }

        delete p1;
        delete p2;

        // now process vector<int> sums and turn into linked list
        bool carry = false;
        for (int i = sums.size() - 1; i >= 0; i--) {
            if (sums[i] >= 10) {
                sums[i] -= 10;
                carry = true;
            }

            if (carry) sums[i+1] += 1;
            carry = false;
        }

        if (sums[sums.size() - 1] >= 10) {
            sums[sums.size() - 1] -= 10;
            sums.push_back(1);
        }

        // create linked list
        for (int i = 0; i < sums.size(); i++) {
            result = new ListNode{sums[i], result};
        }

        return result;
}

int main() {
    ListNode * l1 = new ListNode{9, new ListNode{9, new ListNode{7, new ListNode{9, nullptr}}}};
    ListNode * l2 = new ListNode{5, new ListNode{6, new ListNode{4, nullptr}}};

    ListNode * result = addTwoNumbers(l1, l2);

    // they didn't provide a destructor so...leaks...
}
