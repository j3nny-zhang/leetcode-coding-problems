/*
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
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
    void getParents(TreeNode* root, TreeNode* prev, unordered_map<int, TreeNode*>& m) {
        if (!root) return;
        m[root->val] = prev;
        prev = root;

        getParents(root->left, prev, m);
        getParents(root->right, prev, m);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<int, TreeNode*> m; // val of child, TreeNode parent
       TreeNode *prev = nullptr;
       getParents(root, prev, m);

    //    for (auto &entry : m) {
    //     if (entry.second)
    //         cout << entry.first << " : " << entry.second->val << endl;
    //    }

        queue<TreeNode*> q;
        q.push(target);
        int level = 0;
        vector<int> res;
        unordered_set<int> visited;
        visited.insert(target->val);

        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (level == k) {
                    res.push_back(curr->val);
                }

                if (curr->left && visited.find(curr->left->val) == visited.end()) {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if (curr->right && visited.find(curr->right->val) == visited.end()) {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if (m[curr->val] && visited.find(m[curr->val]->val) == visited.end()){ 
                    q.push(m[curr->val]);
                    visited.insert(m[curr->val]->val);
                }

                size -= 1;
            }
            level += 1;
        }

       return res; 
    }
};
