/**
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
**/

class Solution {
    // dfs to get path
    bool getPath(int curr, int dest, unordered_map<int, vector<double>>& adj, double& path, unordered_set<int>& visited) {
        if (curr == dest) return true;
        if (visited.find(curr) != visited.end()) return false;
        visited.insert(curr);

        for (int i = 0; i < adj[curr].size(); i++) {
            if (adj[curr][i] != -1 && visited.find(i) == visited.end()) {
                double weight = adj[curr][i];
                path *= weight;
                if (getPath(i, dest, adj, path, visited)) return true;
                path /= weight;
            }
        }

        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // convert strings of equations into index for adjacent matrix
        unordered_map<string, int> indices; // {equation value, index}
        int index = 0;

        for (auto equation : equations) {
            string first = equation[0];
            string second = equation[1];

            if (indices.find(first) == indices.end()) {
                indices[first] = index;
                index += 1;
            }

            if (indices.find(second) == indices.end()) {
                indices[second] = index;
                index += 1;
            }
        }

        // convert equations to adjacent matrix
        int n = indices.size();
        vector<vector<double>> matrix (n, vector<double>(n, -1));
        for (int i = 0; i < equations.size(); i++) {
            // get uv edge
            int u = indices[equations[i][0]];
            int v = indices[equations[i][1]];

            matrix[u][v] = (values[i]);
            matrix[v][u] = (1 / values[i]);
        }

        // nodes - equation values
        // directed edges with value, backward direction is 1 / value
        unordered_map<int, vector<double>> adj;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                adj[u].push_back(matrix[u][v]);
            }
        }

        vector<double> res;
        // calculate query values by finding path in the graph
        for (auto query : queries) {

            if (indices.find(query[0]) == indices.end() || indices.find(query[1]) == indices.end()) {
                res.push_back(-1);
                continue;
            }

            int source = indices[query[0]];
            int dest = indices[query[1]];

            double path = 1;
            unordered_set<int> visited;

            bool foundPath = getPath(source, dest, adj, path, visited);

            if (foundPath) {
                res.push_back(path);
            } else {
                res.push_back(-1);
            }
            
        }
        return res;
    }
};
