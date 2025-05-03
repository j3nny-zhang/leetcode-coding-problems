/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        
        bool left = findPath(root->left, target, path);
        bool right = findPath(root->right, target, path);
        if (left || right) return true;

        path.pop_back();
        
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathToP;
        findPath(root, p, pathToP);

        vector<TreeNode*> pathToQ;
        findPath(root, q, pathToQ);

        // put path into unordered set
        unordered_set<TreeNode*> s;

        for (TreeNode* t : pathToP) {
            s.insert(t);
        }

        // check for lca, reverse pathToQ
        for (int i = pathToQ.size() - 1; i >= 0; i--) {
            if (s.find(pathToQ[i]) != s.end()) return pathToQ[i];
        }

        return nullptr;
    }
};

// other solution
class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right) return nullptr;
        if (left && right) return root;

        // after recursion done
        return left == nullptr ? right : left;
    }
};
