/**
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's 
value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
**/

class TimeMap {
    unordered_map<string, map<int, string>> m; // {key, {timestamp, value}}
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";

        if (m[key].find(timestamp) != m[key].end()) return m[key][timestamp];

        // otherwise the largest timestamp_prev <= timestamp
        // ordered maps are default in ascending order, so we search it in reverse
        for (auto it = m[key].rbegin(); it != m[key].rend(); it++) {
            if (it->first < timestamp) return it->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


// this version uses lower_bound which is logn

class TimeMap {
    unordered_map<string, map<int, string>> m; // {key, {timestamp, value}}
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // first check that key is in m
        if (m.find(key) == m.end()) return "";
        auto it = m[key].lower_bound(timestamp);
        if ((*it).first == timestamp) return m[key][timestamp];

        // edge case that it is lower than the smallest timestamp in the map (ie it won't exist)
        if (it == m[key].begin() && (*it).first != timestamp) return "";
        --it;

        return m[key][(*it).first];
    }
};

