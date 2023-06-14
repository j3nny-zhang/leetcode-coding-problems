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

// this solution does not need to traverse all nodes:
class Solution {
    void helper(TreeNode *root, int &k, int& ans) {
        if (root) {
            helper(root->left, k, ans);
            if (--k == 0) {
                ans = root->val;
                return;
            }
            // nodes.push_back(root->val);
            helper(root->right, k, ans);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        helper(root, k, ans);
        return ans;
    }
};
