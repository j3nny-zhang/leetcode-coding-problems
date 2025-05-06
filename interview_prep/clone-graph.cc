/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*> &m) {
        if (node == NULL) {
            return NULL;
        }
        
        if (m.find(node) != m.end()) { // have already made a copy
            return m[node];
        }

        Node* copy = new Node(node->val);
        m[node] = copy;

        for (auto n : node->neighbors) {
            Node* to_place = dfs(n, m);
            copy->neighbors.push_back(to_place);
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m; // maps old nodes to new nodes

        return dfs(node, m);
    }
};
