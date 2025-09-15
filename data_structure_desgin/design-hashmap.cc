/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
*/

class MyHashMap {
    vector<vector<pair<int, int>>> map;
    int BUCKET_SIZE = 10000;

    int hash(int key) {
        return key % BUCKET_SIZE;
    }
public:
    MyHashMap() {
        map.resize(BUCKET_SIZE);
    }
    
    void put(int key, int value) {
        int index = hash(key);

        vector<pair<int, int>>& row = map[index];
        for (auto it = row.begin(); it != row.end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        row.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int index = hash(key);

        vector<pair<int, int>>& row = map[index];
        for (auto it = row.begin(); it != row.end(); it++) {
            if (it->first == key) return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);

        vector<pair<int, int>>& row = map[index];
        for (auto it = row.begin(); it != row.end(); it++) {
            if (it->first == key) {
                row.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
