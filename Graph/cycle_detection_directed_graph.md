## Cycle detection in directed graph
[Problem Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph)


## Using DFS

```
class Solution {
private:
    // Helper function to perform DFS and detect cycles in a directed graph.
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        // Mark the current node as visited.
        vis[node] = 1;
        pathVis[node] = 1; // Mark the node in the current path.

        // Traverse all neighbors of the current node.
        for (auto neighbor : adj[node]) {
            // If the neighbor is not visited, perform DFS on it.
            if (!vis[neighbor]) {
                if (dfs(neighbor, vis, pathVis, adj)) 
                    return true; // Cycle detected.
            }
            // If the neighbor is visited and also part of the current path, it's a cycle.
            else if (pathVis[neighbor]) {
                return true;
            }
        }

        // Backtrack: Unmark the node in the current path.
        pathVis[node] = 0;
        return false; // No cycle detected from this node.
    }

public:
    // Function to detect a cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>>& adj) {
        // Initialize visited and path visited arrays.
        vector<int> vis(V, 0);       // Tracks if a node has been visited.
        vector<int> pathVis(V, 0);   // Tracks nodes in the current path of the DFS.

        // Perform DFS for every unvisited node.
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { 
                if (dfs(i, vis, pathVis, adj)) 
                    return true; // Cycle detected.
            }
        }

        return false; // No cycle detected in the graph.
    }
};
```
