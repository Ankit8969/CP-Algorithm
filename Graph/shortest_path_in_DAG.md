## Shortest path in Directed Acyclic Graph with weighted edges
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

## Input
```
Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2
with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
```

## Solution

```
class Solution {
  public:
  
    void dfs(int u, vector<int>&vis, stack<int> &stk, vector<pair<int,int>> adj[]) {
        vis[u] = 1;
        for(auto x: adj[u]){
            if(!vis[x.first])
                dfs(x.first, vis, stk, adj);
        }
        stk.push(u);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // make graph
        vector<pair<int,int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // get topo sort
        vector<int> vis(V, 0);
        stack<int> stk;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, stk, adj);
            }
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        
        while(stk.size() > 0){
            int node = stk.top();
            stk.pop();
            
            for(auto x: adj[node]){
                int u = x.first;
                int wt = x.second;
                if(dist[node] + wt < dist[u]){
                    dist[u] = dist[node] + wt;
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i] == 1e9)  dist[i] = -1;
        }
        return dist;
    }
};
```

## Shortest path with weighted edegs - 1

You are given an adjacency matrix, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

```
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> dis(n, 1e9);
        queue<pair<int,int>> q;
        q.push({src, 0});
        dis[src] = 0;
        
        while(q.size() > 0) {
            pair<int,int> node = q.front();
            q.pop();
            int u = node.first;
            int dist = node.second;
            
            for(auto x: adj[u]) {
                int newDistance = dist + 1;
                if(newDistance < dis[x]){
                    dis[x] = newDistance;
                    q.push({ x, newDistance });
                }
            }
        }
            
        for(int i=0;i<n;i++){
            if(dis[i] == 1e9)  dis[i] = -1;
        }
        return dis;
        
    }
};
```

