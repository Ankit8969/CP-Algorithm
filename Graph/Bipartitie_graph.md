# BiPartitie Graph
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

[Problem Link](https://leetcode.com/problems/is-graph-bipartite/description/)

## Condition for Bipartitie
- Graph with no cycle
- Cycle having even length

  ## Check bipartitie using BFS
```
class Solution {
private:
    bool bfs(int u, vector<int>&color, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(u);
        color[u] = 0;

        while(q.size() > 0){
            int node = q.front();
            q.pop();
            for(auto x: graph[node]) {
                if(color[x] == -1){
                    color[x] = !color[node];
                    q.push(x);
                }else if(color[x] == color[node])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1 && !bfs(i, color, graph))
                return false;
        }
        return true;
    }
};

```


## Check bipartitie using DFS

```
class Solution {
private:
    bool dfs(int u, int par, int currColor, vector<int>&color, vector<vector<int>>& graph) {
        color[u] = currColor;
        for(auto x: graph[u]) {
            if(x == par)    continue;
            if (color[x] == -1) { // If the node is not yet colored
                if (!dfs(x, u, !currColor, color, graph)) // Alternate color
                    return false;
            } else if (color[x] == color[u]) { // If the adjacent node has the same color
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, -1, 0, color, graph)) { // Start DFS with color 0
                    return false;
                }
            }
        }
        return true;
    }
};

```


