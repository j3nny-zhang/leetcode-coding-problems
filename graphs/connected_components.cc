// num of components in undirected graph, where edges is [ai, bi] edges

// dfs
class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.find(node) != visited.end()) return;
        visited.insert(node);

        for (int neighbour : adj[node]) {
            dfs(neighbour, adj, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // convert to adjacency list
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // run dfs on all components
        unordered_set<int> visited;
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                dfs(i, adj, visited);
                components += 1;
            }
        }

        return components;
    }
};

// bfs
class Solution {
public:
    void bfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        queue<int> q;
        q.push(node);
        visited.insert(node);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbour : adj[curr]) {
                if (visited.find(neighbour) == visited.end()) {
                    visited.insert(neighbour);
                    bfs(neighbour, adj, visited);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // convert to adjacency list
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // run dfs on all components
        unordered_set<int> visited;
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                bfs(i, adj, visited);
                components += 1;
            }
        }

        return components;
    }
};
