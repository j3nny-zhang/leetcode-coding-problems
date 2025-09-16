/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are 
performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. 
It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. 
But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 
*/

struct Node {
    int value;
    Node* next;

    Node() {}
    Node(int value) : value{value} {}
};

struct LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
};

class MyCircularQueue {
    LinkedList* ll;
    int capacity = 0;
    int count = 0;
public:
    MyCircularQueue(int k) {
        capacity = k;
        ll = new LinkedList();
    }
    
    bool enQueue(int value) {
        if (count == capacity) return false;
        Node* head = new Node(value);

        Node* node = new Node(value);
        if (count == 0) {
            ll->head = ll->tail = node;
            node->next = node; // circular link
        } else {
            node->next = ll->head;
            ll->tail->next = node;
            ll->tail = node;
        }

        count += 1;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) return false;
        count -= 1;

        if (ll->head == ll->tail) {
            delete ll->head;
            ll->head = ll->tail = nullptr;
        } else {
            Node* temp = ll->head;
            ll->head = ll->head->next;
            ll->tail->next = ll->head; 
            delete temp;
        }

        return true;
    }
    
    int Front() {
        if (count == 0) return -1;
        return ll->head->value;
    }
    
    int Rear() {
        if (count == 0) return -1;
        return ll->tail->value;
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
