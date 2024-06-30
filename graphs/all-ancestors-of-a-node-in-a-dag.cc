/*
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). 
The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.
*/

class Solution {
    void dfs(int parent, int curr, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, vector<vector<int>>& ancestorList) {
        visited.insert(curr);

        for (int neighbour : adjList[curr]) {
            if (visited.find(neighbour) == visited.end()) {
                ancestorList[neighbour].push_back(parent);
                dfs(parent, neighbour, adjList, visited, ancestorList);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // create adjList
        unordered_map<int, vector<int>> adjList;

        for (vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> ancestorList(n);

        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            dfs(i, i, adjList, visited, ancestorList);
        }

        // sort ancestors
        for (vector<int> ancestors : ancestorList) {
            sort(ancestors.begin(), ancestors.end());
        }

        return ancestorList;
    }
};
