/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
    void helper(TreeNode *root, vector<int>& nodes) {
        if (root) {
            helper(root->left, nodes);
            nodes.push_back(root->val);
            helper(root->right, nodes);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        helper(root, nodes);
        return nodes[k-1];
    }
};
