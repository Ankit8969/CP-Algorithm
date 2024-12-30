## Dijkastra Alogrithm
Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the 
source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.

- Dijkastra doesn't work with the negative weights.

## Using Priority_queue

```
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq; // min heap
        
        pq.push({ 0, src }); // distance - node
        dis[src] = 0;
        
        while(pq.size() > 0) {
            pair<int,int> top = pq.top();
            pq.pop();
            
            int dist = top.first;
            int node = top.second;
            
            for(auto x: adj[node]) {
                int newDistance = dist + x.second;
                if(newDistance < dis[x.first]) {
                    dis[x.first] = newDistance;
                    pq.push({ newDistance, x.first });
                }
            }
        }
        
        return dis;
    }
};

```



## Algorithm using Set data structure
```
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        
        set<pair<int,int>> st; // min heap
        
        st.insert({ 0, src }); // distance - node
        dis[src] = 0;
        
        while(st.size() > 0) {
            pair<int,int> top = *(st.begin());
            st.erase(top);
            
            int dist = top.first;
            int node = top.second;
            
            for(auto x: adj[node]) {
                int newDistance = dist + x.second;
                if(newDistance < dis[x.first]) {
                    dis[x.first] = newDistance;
                    st.insert({ newDistance, x.first });
                }
            }
        }
        
        return dis;
    }
};
```




