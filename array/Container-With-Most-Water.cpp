/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int prod = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            int width = right - left;
            int temp_height = min(height[left], height[right]);
            prod = max(prod, temp_height * width);
            
            if (height[left] <= height[right]) left += 1;
            else right -= 1;
        }
        
        return prod;
    }
};
