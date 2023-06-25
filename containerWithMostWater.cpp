/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
*/ 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            int area = (r-l) * (min(height[l], height[r]));
            result = max(area, result);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return result;
    }
};
