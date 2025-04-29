/*
Given two version strings, version1 and version2, compare them. 
A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. 
If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:
Input: version1 = "1.2", version2 = "1.10"
Output: -1
Explanation:
version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation:
Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 3:
Input: version1 = "1.0", version2 = "1.0.0.0"
Output: 0
Explanation:
version1 has less revisions, which means every missing revision are treated as "0".
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2) return 0;

        istringstream v1{version1};
        istringstream v2{version2};

        string temp;
    
        vector<int> v1_nums;
        while(getline(v1, temp, '.')) {
            v1_nums.push_back(stoi(temp));
        }

        vector<int> v2_nums;
        while(getline(v2, temp, '.')) {
            v2_nums.push_back(stoi(temp));
        }

        //for (auto s : v1_nums) cout << stoi(s) << endl;

        int m = v1_nums.size();
        int n = v2_nums.size();
        int length;

        if (m < n) {
            for (int i = m; i < n; i++) v1_nums.push_back(0);
            length = n;
        }

        // for (int s : v1_nums) cout << s << ".";
        // cout << endl;
        // for (int s : v2_nums) cout << s << ".";
        // cout << endl;


        if (n < m) {
            for (int i = n; i < m; i++) v2_nums.push_back(0);
            length = m;
        }

        int i = 0;
        while(true) {
            if (i == length) return 0;

            if (v1_nums[i] < v2_nums[i]) return -1;
            if (v1_nums[i] > v2_nums[i]) return 1;

            i++;
        }

        return 0;
    }
};
