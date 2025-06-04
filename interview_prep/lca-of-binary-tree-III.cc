/*
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: 
"The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants 
  (where we allow a node to be a descendant of itself)."
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    void findPath(Node *n, vector<Node *>& path) {
        if (!n) return;
        path.push_back(n);
        findPath(n->parent, path);
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {

        // find path for p
        vector<Node *> pathToP;
        findPath(p, pathToP);

        // find path for q
        vector<Node *>pathToQ;
        findPath(q, pathToQ);

        /// put in set to find LCA
        unordered_set<Node *> s;
        for (auto n : pathToP) {
            s.insert(n);
        }

        for (auto n : pathToQ) {
            if (s.find(n) != s.end()) return n;
        }

        return nullptr;
    }
};

// more optimal solution
// It is just a variation of Intersection of LinkedList!
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p;
        Node* b = q;
        while(a != b) {
            a = a == nullptr ? q : a->parent;
            b = b == nullptr ? p : b->parent;  
        }
        return a;
    }
};
