// Given the root node of a binary search tree and two integers low and high, 
// return the sum of values of all nodes with a value in the inclusive range [low, high].

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
    void helper(TreeNode* root, int low, int high, int& sum) {
        if (!root) return;
        if (root->val >= low && root->val <= high) sum += root->val;
        helper(root->left, low, high, sum);
        helper(root->right, low, high, sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        helper(root, low, high, sum);
        return sum;
    }
};
