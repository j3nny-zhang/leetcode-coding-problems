/*
Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. 
If there are multiple answers, print the smallest.

Example 1:

Input: root = [4,2,5,1,3], target = 3.714286
Output: 4

Example 2:

Input: root = [1], target = 4.428571
Output: 1
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
    void helper(TreeNode* node, double target, double& diff, TreeNode *&res) {
        if (!node) return;

        helper(node->left, target, diff, res);

        if (abs(target - node->val) < diff) {
            res = node;
            diff = abs(target - node->val);
        }

        helper(node->right, target, diff, res);

    }
    
public:
    int closestValue(TreeNode* root, double target) {
        double diff = INT_MAX;
        TreeNode* res = nullptr;
        helper(root, target, diff, res);

        return res->val;
    }
};
