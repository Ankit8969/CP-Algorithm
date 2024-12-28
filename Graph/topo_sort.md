## Topological sort

Topological sort is an ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge 
(𝑢,𝑣) (u,v), vertex u comes before v in the ordering.

## Key Points:
- Only applicable to DAGs (Directed Acyclic Graphs).
- It’s widely used in scheduling problems, like task dependency resolution.


## TopoSort using DFS

```
class Solution {
  public:
  
    void dfs(int u, vector<int> &vis, stack<int> &stk, vector<vector<int>>& adj) {
        vis[u] = 1;
        for(auto x: adj[u]){
            if(!vis[x])
                dfs(x, vis, stk,adj);
        }
        stk.push(u);
        return ;
    }
  
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> stk;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, stk, adj);
            }
        }
        vector<int> ans;
        while(stk.size() > 0){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
```


## Kahn's Algorithm (BFS-Based Approach)

This method uses in-degree (number of incoming edges) to find a valid topological order:

- Calculate in-degree for each vertex.
- Use a queue to store vertices with in-degree 0.
- Remove vertices with in-degree 0 and reduce the in-degree of their neighbors.
- Repeat until all nodes are processed.

```
class Solution {
public:
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> inDegree(V, 0);

        // Calculate in-degree for all nodes.
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }

        // Push all nodes with in-degree 0 to the queue.
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS.
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            // Reduce the in-degree of neighbors.
            for (auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the graph has a cycle, the topological order is invalid.
        if (topoOrder.size() != V) {
            return {}; // Graph is not a DAG.
        }

        return topoOrder;
    }
};
```


