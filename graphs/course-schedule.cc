/* 
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

// The idea here is to find whether or not there is a cycle in the graph
class Solution {
    bool dfs(int course, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, unordered_set<int>& cycle) {
        if (visited.find(course) != visited.end()) return true;
        if (cycle.find(course) != cycle.end()) return false;

        cycle.insert(course);

        for (int n : adjList[course]) {
            if (!dfs(n, adjList, visited, cycle)) return false;
        }

        cycle.erase(course);
        visited.insert(course);

        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;
        unordered_set<int> cycle;

        // initialize adjList, where each course maps to a vector of its prerequisites
        for (auto prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adjList, visited, cycle)) return false;
        }


        return true;
    }
};




class Solution {
    bool dfs(int course, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, vector<vector<int>>& prerequisites) {
        if (visited.find(course) != visited.end()) return false; // there is a cycle!
        if (adjList[course].size() == 0) return true; // base case, no prerequisites

        visited.insert(course);

        for (int prereq : adjList[course]) {
            if (!dfs(prereq, adjList, visited, prerequisites)) return false;
        }

        // everything in adjList[course] has returned true
        adjList[course].clear();
        visited.erase(course);

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;

        // initialize adjList, where each course maps to a vector of its prerequisites
        for (auto prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adjList, visited, prerequisites)) return false;
        }


        return true;
    }
};
