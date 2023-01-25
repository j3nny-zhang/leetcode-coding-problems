// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, vector<string>> m;
        
        for (string s : strs) {
            vector<int> key(26, 0);
            for (char c : s) {
                key[c - 'a'] += 1;
            }
            m[key].push_back(s);
        }

        for (auto value : m) {
            result.push_back(value.second);
        }

        return result;
    }
};
