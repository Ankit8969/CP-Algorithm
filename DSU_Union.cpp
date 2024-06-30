************Practice Question****************
  https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/?envType=daily-question&envId=2024-06-30
  youtube - https://www.youtube.com/watch?v=zEAmQqOpfzM
***************************************************


class Solution {
public:
    
    static bool comp(vector<int> A, vector<int> B){
        if (A[0] <= B[0])    return false;
        return true;
    }
    
    void make(int v, vector<int>&parent,vector<int>&size){
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v,vector<int>&parent,vector<int>&size) {
        if (parent[v] == v) return v;
        // path compression
        return parent[v] = find(parent[v], parent, size);
    }

    void Union(int a, int b,vector<int>&parent,vector<int>&size) {
        a = find(a, parent, size);
        b = find(b, parent, size);
        if (a != b){
            // Union by size.
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> AliceParent(n+3), BobParent(n+3);
        vector<int> Alicesize(n+3), BobSize(n+3);
        // Mainting two DSU for both alice and bob
        for (int i=1;i<=n;i++) {
            make(i,AliceParent,Alicesize);
            make(i,BobParent,BobSize);
        }

        sort(edges.begin(), edges.end(), comp);
        int number_of_removed_edges = 0;

        for (int i=0;i<edges.size();i++) {
            // for Alice
            int p1 = find(edges[i][1], AliceParent, Alicesize);
            int p2 = find(edges[i][2], AliceParent, Alicesize);
            // for Bob
            int p3 = find(edges[i][1], BobParent, BobSize);
            int p4 = find(edges[i][2], BobParent, BobSize);
            
            if (edges[i][0] == 3){
                // it means for both case
                bool flag = true;
                if (p1 != p2){
                    flag = false;
                    Union(edges[i][1], edges[i][2], AliceParent, Alicesize);
                }
                if(p3 != p4) {
                    flag = false;
                    Union(edges[i][1], edges[i][2], BobParent, BobSize);
                }
                if (flag)
                    number_of_removed_edges++;
            }else if (edges[i][0] == 1){
                if (p1 != p2)
                    Union(edges[i][1], edges[i][2], AliceParent, Alicesize);
                else
                    number_of_removed_edges++;
            }else {
                if(p3 != p4)
                    Union(edges[i][1], edges[i][2], BobParent, BobSize);
                else
                    number_of_removed_edges++;
            }
        }
        int number_of_connected_comp_alice = 0, number_of_connected_comp_bob = 0;
        for (int i=1;i<=n;i++)
            if (AliceParent[i] == i) 
                number_of_connected_comp_alice++;
        
        for (int i=1;i<=n;i++)
            if (BobParent[i] == i)  
                number_of_connected_comp_bob++;

        
        return (number_of_connected_comp_alice == 1 && number_of_connected_comp_bob == 1) ? number_of_removed_edges: -1;
    }
};
