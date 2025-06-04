/*
Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        unordered_map<int, vector<int>> m; // {col #, vector of root values}
        queue<pair<int, TreeNode*>> q; // col #, node}

        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        q.push({0, root});

        while (!q.empty()) {
            int index = q.front().first;
            TreeNode* curr = q.front().second;
            q.pop();

            minCol = min(minCol, index);
            maxCol = max(maxCol, index);

            // add to map
            m[index].push_back(curr->val);

            if (curr->left) {
                q.push({index - 1, curr->left});
            }

            if (curr->right) {
                q.push({index + 1, curr->right});
            }
        }

        int i = minCol;
        vector<vector<int>> res;

        while (i <= maxCol) {
            res.push_back(m[i]);
            i += 1;
        }

        return res;
    }
};
