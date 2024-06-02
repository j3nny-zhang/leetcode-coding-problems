/**
Given the root of a binary tree, return the zigzag level order traversal of its nodes' 
values. (i.e., from left to right, then right to left for the next level and alternate between).
**/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            vector<int> currLevel;

            int size = q.size();
            TreeNode *curr;
            while(size-- > 0) {
                curr = q.front();
                q.pop();

                currLevel.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
            }

            if (level % 2 == 1) reverse(currLevel.begin(), currLevel.end());
            result.push_back(currLevel);
            level += 1;
        }

        return result;
    }
};
