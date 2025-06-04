/*
There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. 
Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
*/
 

Example 1:

Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
Example 2:

Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        if (heights.size() == 1) return {0};
        
        vector<int> res;
        int height = heights[heights.size()-1];
        res.push_back(heights.size()-1);

        for (int i = heights.size()-2; i >= 0; i--) {
            if (heights[i] > height) {
                res.push_back(i);
                height = max(heights[i], height);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
