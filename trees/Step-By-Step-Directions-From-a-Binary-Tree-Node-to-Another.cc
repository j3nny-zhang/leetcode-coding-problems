/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. 
You are also given an integer startValue representing the value of the start node s, and a different integer destValue
representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a 
string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t
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
    bool getPath(TreeNode* root, int dest, string &path) {
        if (!root) return false;
        if (root->val == dest) return true;

        bool leftPath = getPath(root->left, dest, path);
        if (leftPath) {
            path += "L";
            return true;
        }

        bool rightPath = getPath(root->right, dest, path);
        if (rightPath) {
            path += "R";
            return true;
        }

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // get path from root to startValue (reversed)
        string rootToStart = "";
        getPath(root, startValue, rootToStart);
        reverse(rootToStart.begin(), rootToStart.end());

        // get path from root to destValue (reversed)
        string rootToDest = "";
        getPath(root, destValue, rootToDest);
        reverse(rootToDest.begin(), rootToDest.end());


        int i = 0;
        int j = 0;

        int lengthToStart = rootToStart.size();
        int lengthToDest = rootToDest.size();

        while (i < lengthToStart && j < lengthToDest && rootToStart[i] == rootToDest[j]) {
            i += 1;
            j += 1;
        }

        string finalPath = "";
        // change leftover to "U" in rootToStart
        for (int k = i; k < lengthToStart; k++) {
            finalPath += "U";
        }

        // add leftover path from rootToDest
        for (int k = j; k < lengthToDest; k++) {
            finalPath += rootToDest[k];
        }

        // cout << "toStart: " + rootToStart << " | i: " << i << endl;
        // cout << "toDest: " + rootToDest << " | j: " << j ;

        return finalPath;
    }
};
