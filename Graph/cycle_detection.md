## Cycle detection in Graph using BFS
[GFG ProblemLink](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph)

```

bool BFS(int k, vector<vector<int>>& adj, vector<int> &vis) {
      queue<pair<int,int>> q;
      q.push({k, -1});
      vis[k] = 1;
      
      while(!q.empty()) {
          pair<int,int> topNode = q.front();
          q.pop();
          
          for(auto x: adj[topNode.first]) {
              if(!vis[x]) {
                  vis[x] = 1;
                  q.push({x, topNode.first});
              }else if(x != topNode.second){
                  return true;
              }
          }
      }
      return false;
  }

  bool isCycle(vector<vector<int>>& adj) {
      // BFS
      int n = adj.size();
      vector<int> vis(n, 0);
      
      for(int k=0;k<n;k++){
          if(!vis[k] && BFS(k, adj, vis))   return true;
      }
      
      return false;
  }

```


## Cycle detection using DFS

```
bool dfs(int u, int par, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (auto x : adj[u]) {
        if (!vis[x]) {
            // Recursive call to DFS
            if (dfs(x, u, adj, vis)) {
                return true;
            }
        } else if (x != par) {
            // A visited node that is not the parent indicates a cycle
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0); // Visited array

    // Check each component of the graph
    for (int k = 0; k < n; k++) {
        if (!vis[k] && dfs(k, -1, adj, vis)) {
            return true;
        }
    }

    return false; // No cycle found
}

```






