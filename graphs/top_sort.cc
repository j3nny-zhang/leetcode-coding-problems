// kahn's algorithm
vector<int> topSort(vector<vector<int>>& adjList, int V) {

  vector<int< indegree(V);
  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) q.push(i);
  }

  vector<int> res;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    res.push_back(node);

    for (auto it : adj[node]) {
      indegree[it]--;
      if (indegree[it] == 0) q.push(it);
    }

    if (res.size() != V) cout << "contains cycle" << endl;

    return result;
  }
}

// using stack
void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
  visited[v] = true;
  for (int i : adj[v]) {
    if (!visited[i]) dfs(i, adj, visited, st);
  }
  st.push(v);
}


vector<int> topSort(vector<vector<int>>& adj) {
  int V = adj.size();
  stack<int> st;
  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i])
    dfs(i, adj, visited, st);
  }

  vector<int> ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}
