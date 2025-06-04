/*
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
*/

class Solution {
public:
    bool hasCycle(int node, int parent, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.find(node) != visited.end()) return false;
        visited.insert(node);

        for (int neighbour : adj[node]) {
            // if adjacent has been visited and is not the parent
            if (visited.find(neighbour) != visited.end() && neighbour != parent) return true;
            if (hasCycle(neighbour, node, adj, visited)) return true;
        }
        
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // create adjacency list
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // if there is a cycle, then the graph is not a tree
        unordered_set<int> visited;

        if (hasCycle(0, -1, adj, visited)) return false;
        if (visited.size() != n) return false;

        return true;

    }
};
