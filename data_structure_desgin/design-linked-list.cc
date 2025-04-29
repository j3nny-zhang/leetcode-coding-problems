struct Node {
    int val;
    Node *next;
};

class MyLinkedList {
    Node *head = nullptr;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) { // done
        // if (index == 0 && head) {
        //     return head->val;
        // }

        int i = 0;
        Node *tmp = head;
        while (tmp) {
            if (i == index) {
                int ans = tmp->val;

                // manage memory
                tmp = nullptr;
                delete tmp;
                return ans;
            }
            i += 1;
            tmp = tmp->next;
        }

        // manage memory
        tmp = nullptr;
        delete tmp;
        return -1;
    }
    
    void addAtHead(int val) { // done
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }
    
    void addAtTail(int val) { // done
        Node *n = new Node(val);
        if (head == nullptr) {
            head = n;
            return;
        }

        Node *tmp = head;

        while (tmp->next) {
            tmp = tmp->next;
        }

        tmp->next = n;

        // manage memory
        tmp = nullptr;
        delete tmp;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node *tmp = head;
        int i = 0;
        while (tmp) {
            if (i == index - 1) {
                Node *n = new Node(val);
                n->next = tmp->next;
                tmp->next = n;
            }
            tmp = tmp->next;
            i += 1;
        }

        // manage memory
        tmp = nullptr;
        delete tmp;
    }
    
    void deleteAtIndex(int index) {
        if (index == 0 && head) {
            head = head->next;
            // need to manage memory
            return;
        }

        Node *tmp = head;
        Node *prev= nullptr;

        int i = 0;
        while (tmp) {
            if (i == index) {
                if (tmp->next) {
                    prev->next = tmp->next;
                    // free memory
                    return;
                } else { // last node
                    prev->next = nullptr;
                    // free memory
                    return;
                }
            }
            prev = tmp;
            tmp = tmp->next;
            i += 1;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
