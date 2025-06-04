/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
    int capacity = 0;
    int size = 0;
    unordered_map<int, Node*> m;
    Node* head = nullptr;
    Node* tail = nullptr;

    void remove(Node* node) {
        size -= 1;

        Node* tmpPrev = node->prev;
        Node* tmpNext = node->next;

        tmpPrev->next = tmpNext;
        tmpNext->prev = tmpPrev;
    }

    void insert(Node* mru) { // inserts at the head -> mru
        size += 1;

        Node *tmp = head->prev;
        tmp->next = mru;
        mru->prev = tmp;
        mru->next = head;
        head->prev = mru;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        // init doubly linked list
        head = new Node{-1, -1}; // mru
        tail = new Node{-1, -1}; // lru

        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            int value = m[key]->value;
            Node* mru = new Node(key, value);

            // make new node MRU
            remove(m[key]);
            insert(mru);

            m[key] = mru;

            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* mru = new Node(key, value);

            // make new node MRU
            remove(m[key]);
            insert(mru);

            m[key] = mru;

        } else {
            if (size == capacity) {
                
                // evict LRU
                m.erase(tail->next->key);
                remove(tail->next);
            } 
            // make new node MRU
            Node* mru = new Node(key, value);
            insert(mru);
            m[key] = mru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
