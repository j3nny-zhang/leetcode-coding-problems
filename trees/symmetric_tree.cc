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
    bool mirrored(TreeNode *nodeLeft, TreeNode *nodeRight) {
        if (nodeLeft == nullptr && nodeRight == nullptr) return true;
        if (nodeLeft == nullptr || nodeRight == nullptr) return false;
        if (nodeLeft->val != nodeRight->val) return false;
        return (mirrored(nodeLeft->left, nodeRight->right) && mirrored(nodeLeft->right, nodeRight->left));

    }

    bool isSymmetric(TreeNode* root) {
        return (mirrored(root->left, root->right));
    }
};
