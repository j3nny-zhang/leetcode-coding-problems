/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_new; // {old node, new node}

        // copy nodes into the map
        Node* p = head;
        while (p) {
            old_new[p] = new Node(p->val);
            p = p->next;
        }

        // now created the linkedlist with the correct pointers
        p = head;
        while (p) {
            old_new[p]->next = old_new[p->next];
            old_new[p]->random = old_new[p->random];

            p = p->next;
        }

        return old_new[head];
    }
};
