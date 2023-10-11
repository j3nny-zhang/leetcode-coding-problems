/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, 
and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> m; // hand, count

        for (int n : hand) {
            m[n] += 1;
        }

        for (int n : hand) { 
            if (m[n] == 0) continue; 
            int i = groupSize;

            int card = n;
            while (i > 0) {
                if (m.find(card) == m.end()) return false;
                m[card] -= 1;
                card += 1;
                i -= 1;
            }
        }

        for (auto entry : m) {
            if (entry.second != 0) return false;
        }
        return true;
    }
};
