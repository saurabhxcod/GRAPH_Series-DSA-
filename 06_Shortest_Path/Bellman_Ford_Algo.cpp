// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(vector<int>&edge:edges){
                int node=edge[0];
                int nbr=edge[1];
                int wt=edge[2];
                
                if(dist[node]==INT_MAX) continue;
                int new_dist=dist[node]+wt;
                if(new_dist<dist[nbr]) dist[nbr]=new_dist;
            }
        }
        
        for(vector<int>&edge:edges){
                int node=edge[0];
                int nbr=edge[1];
                int wt=edge[2];
                
                if(dist[node]==INT_MAX) continue;
                int new_dist=dist[node]+wt;
                if(new_dist<dist[nbr]) return {-1};
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=1e8;
            }
        }
        return dist;
        
    }
};
