/**
You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of 
indices i for which nums1[i] > nums2[i].

Return any permutation of nums1 that maximizes its advantage with respect to nums2.

 

Example 1:

Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
Example 2:

Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
Output: [24,32,8,12]
**/

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
       vector<int> res;
       sort(nums1.begin(), nums1.end());

       for (int n : nums2) {
        auto it = upper_bound(nums1.begin(), nums1.end(), n);

        if (it == nums1.end()) {
            res.push_back(*nums1.begin());
            nums1.erase(nums1.begin());
        } else {
            res.push_back(*it);
            nums1.erase(it);
        }
       }

       return res; 
    }
};
