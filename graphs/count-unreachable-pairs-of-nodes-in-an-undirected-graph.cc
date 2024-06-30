/*
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Example 1:

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Example 2:
  
Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
*/

class Solution {
    void dfs(int curr, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, long long &size) {
        if (visited.find(curr) != visited.end()) return;
        visited.insert(curr);
        size += 1;

        for (int neighbour : adjList[curr]) {
            dfs(neighbour, adjList, visited, size);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // the idea is find number of components (only need to keep track of # of nodes in component)

        // first turn edges into adjList
        unordered_map<int, vector<int>> adjList;
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_set<int> visited;
        vector<long long> components; // each components[i] represents the size of component i

        for (int i = 0; i < n; i++) {
            long long size = 0;
            if (visited.find(i) == visited.end()) {
                dfs(i, adjList, visited, size);
            }

            if (size != 0) {
                components.push_back(size);
            }
        }

        if (components.size() == 1) return 0;

        long long result = 1;

        for (long long component : components) {
            // for each component, you can make a pair with the nodes not in the component
            result += (component * (n - component)); 
        }
        return result / 2; // since we double count the pairs
    }
};
