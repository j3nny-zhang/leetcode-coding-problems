/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
*/

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
    unordered_map<int, Node*> m;
    Node *head = nullptr; // doubly linked list
    Node *tail = nullptr;

    int capacity = 0;

    void insert(Node *node) { // insert to the front of the doubly linked list
        Node *tmp = head->next;
        node->next = tmp;
        tmp->prev = node;
        node->prev = head;
        head->next = node;

        // free memory
        tmp = nullptr;
        delete(tmp);
    }

    void remove(Node *node) { // remove node when no longer in map
        Node *tmpPrev = node->prev;
        Node *tmpNext = node->next;

        tmpPrev->next = tmpNext;
        tmpNext->prev = tmpPrev;

        delete(node);
    }


public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        // initialize the doubly linked list
        head = new Node(-1, -1); // represent MRU
        tail = new Node(-1, -1); // represent LRU
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            // most recently used
            int value = m[key]->value;
            Node *mru = new Node(key, value);

            remove(m[key]);
            insert(mru);
            m[key] = mru;
            
            return m[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()) {
           Node *node = new Node(key, value);
           insert(node);
           m[key] = node; 
        } else {
            // becomes mru
            Node *mru = new Node(key, value);
            remove(m[key]);
            insert(mru);
            m[key] = mru;
        }
        
        if (m.size() > capacity) {
            Node *lru = tail->prev;
            m.erase(lru->key);
            remove(lru);
        }      
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
