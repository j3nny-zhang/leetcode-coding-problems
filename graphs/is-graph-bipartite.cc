/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. 
The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

class Solution {
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbour : graph[curr]) {
                if (visited[neighbour] == -1) {
                    visited[neighbour] = !visited[curr];
                    q.push(neighbour);
                } else if (visited[neighbour] == visited[curr]) { // visited neighbour but it has the same colour as its adj node
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        // so we want to colour each node, such that every adj u,v pair are of different colours
        // if whenever we find an adj u,v pair with the same colour, then the graph is not bipartite

        int n = graph.size();
        vector<int> visited(n, -1); // colour 0 or 1

        // bfs for each component
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                if (!bfs(i, graph, visited)) return false;
            }
        }
        
        return true;
    }
};
