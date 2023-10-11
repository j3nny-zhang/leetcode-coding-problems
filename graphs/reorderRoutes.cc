/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities 
(this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.


Example 1:

Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // let a negative number be a node facing "outward" from 0
        unordered_map<int, vector<int>> neighbours;

        for (vector<int> connection : connections) {
            neighbours[connection[0]].push_back(-connection[1]);
            neighbours[connection[1]].push_back(connection[0]);
        }

        int count = 0;
        unordered_set<int> visited;
        queue<int> bfs;
        bfs.push(0);

        while (!bfs.empty()) {
            int node = bfs.front();
            bfs.pop();
            for (int neighbour : neighbours[node]) {
                if (visited.find(abs(neighbour)) == visited.end()) {
                    bfs.push(abs(neighbour));
                    if (neighbour < 0) count += 1;
                    visited.insert(abs(neighbour));
                }  
            }
        }

        return count;
    }
};

// -- bfs --
class Solution {
    void dfs(unordered_map<int, vector<int>> &neighbours, unordered_set<int> &visited, int &count, int node) {
        if (visited.find(abs(node)) != visited.end()) return;
        if (node < 0) count += 1;
        visited.insert(abs(node));

        for (int n : neighbours[abs(node)]) {
            dfs(neighbours, visited, count, n);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        // let a negative number be a node facing "outward" from 0
        unordered_map<int, vector<int>> neighbours;

        for (vector<int> connection : connections) {
            neighbours[connection[0]].push_back(-connection[1]);
            neighbours[connection[1]].push_back(connection[0]);
        }

        int count = 0;
        unordered_set<int> visited;
        
        dfs(neighbours, visited, count, 0);

        return count;
    }
};
