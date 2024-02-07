// Given a binary tree, determine if it is height-balanced

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
    int isBalancedHelper(TreeNode* root, bool& isBalanced) {
        if (!root) return 0;
        int left = isBalancedHelper(root->left, isBalanced);
        int right = isBalancedHelper(root->right, isBalanced);

        if (abs(left - right) > 1) {
            isBalanced = false;
            return -1;
        }

        return 1 + max(left, right);

    }

public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        isBalancedHelper(root, balanced);
        return balanced;
    }
};
