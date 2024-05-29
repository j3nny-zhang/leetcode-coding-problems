// Given the root of a binary tree and an integer targetSum, 
//   return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children.

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

    bool helper(TreeNode *curr, int currSum, int targetSum) {
        if (!curr) return false;
        if (!curr->left && !curr->right) return (currSum + curr->val == targetSum);
        bool l = helper(curr->left, currSum + curr->val, targetSum);
        bool r = helper(curr->right, currSum + curr->val, targetSum);

        return l || r;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0, targetSum);
    }
};
