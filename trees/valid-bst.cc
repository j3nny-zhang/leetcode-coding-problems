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
    void BSTSortedArray(TreeNode* root, vector<int>& result) {
        if (!root) return;
        BSTSortedArray(root->left, result);
        result.push_back(root->val);
        BSTSortedArray(root->right, result);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        BSTSortedArray(root, result);

        for (int i = 1; i < result.size(); i++) {
            if (result[i-1] >= result[i]) return false;
        }
        return true;
    }
};
