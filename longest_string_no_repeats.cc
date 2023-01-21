#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// return length of longest substring that contains no duplicate characters
// very slow runtime hmmmm ... surely there's a more efficient solution

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> seen = {};
    int length = 0;
    int max_length = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (seen.find(s[i]) != seen.end()) { // found a repeat char
            length = 0;
            int index_of_seen = seen[s[i]] + 1; // start index to after the first occurence of repeated char
            i = index_of_seen;
            seen.clear();
        }
        seen[s[i]] = i;
        length += 1;
        max_length = max(length, max_length);
    }

    return max_length;     
}

int main() {
    string s = "dvadf";
    int result = lengthOfLongestSubstring(s);

    cout << result << endl;
}
