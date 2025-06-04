/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
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
    TreeNode* deleteNode(TreeNode* node, unordered_set<int>& s, vector<TreeNode*>& res) {
        if (!node) return nullptr;
        node->left = deleteNode(node->left, s, res);
        node->right = deleteNode(node->right, s, res);
        
        if (s.find(node->val) != s.end()) {
            if (node->left) res.push_back(node->left);
            if (node->right) res.push_back(node->right);

            delete node;
            return nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s;
        for (int n : to_delete) s.insert(n);
        root = deleteNode(root, s, res);

        if (root) res.push_back(root);
        return res;
    }
};
