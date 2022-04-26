class Solution { // O(n) time
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for (int i = 0; ; ++i) {
            auto to_find = m.find(target - nums[i]);
            
            if (to_find != m.end()) {
                return vector<int> {i, to_find->second};
            }
            
            m[nums[i]] = i;
        }
    }
};
