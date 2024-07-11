/*
You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, 
return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair{cost, node}, min heap
        pq.push(pair<int, int>{0, k}); 
        vector<int> costs(n + 1, INT_MAX);
        costs[k] = 0;

        // turn graph into adjList
        unordered_map<int, vector<pair<int, int>>> adjList; // pair{v, weight}
        for (vector<int> &edge : times) {
            adjList[edge[0]].push_back(pair<int, int>{edge[1], edge[2]});
        }

        // run dijkstra
        while (!pq.empty()) {
            int u = pq.top().second;
            int total_cost = pq.top().first;
            pq.pop();

            for (pair<int, int> &neighbour : adjList[u]) {
                int v = neighbour.first;
                int cost = neighbour.second;

                if (costs[u] + cost < costs[v]) {
                    costs[v] = costs[u] + cost;
                    pq.push(pair<int, int>{costs[v], v});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (costs[i] == INT_MAX) return -1;
            ans = max(ans, costs[i]);
        }

        return ans;
    }
};
