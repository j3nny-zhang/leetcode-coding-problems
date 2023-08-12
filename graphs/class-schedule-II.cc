/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.
*/ 

class Solution {  
    bool dfs(int course, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& result) {
        if (visited.find(course) != visited.end()) return true;
        if (cycle.find(course) != cycle.end()) return false;

        cycle.insert(course);
        for (int n : adjList[course]) {
            if (!dfs(n, adjList, visited, cycle, result)) return false;
        }
        cycle.erase(course); // not apart of the path anymore
        visited.insert(course);
        result.push_back(course);

        return true;
    }
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visited;
        unordered_set<int> cycle;
        unordered_map<int, vector<int>> adjList;

        vector<int> result;

        // initialize adjList
        for (vector<int> p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adjList, visited, cycle, result)) return {};
        }

        return result;
    }
};
