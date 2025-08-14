class Solution {
  public:
  
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>current_path){
        visited[node]=1;
        current_path[node]=1;
        for(int nbr:adj[node]){
           if(!visited[nbr]){
               int result=dfs(nbr,adj,visited,current_path);
               if(result) return true;
           }
           else{
               if(current_path[node]==1) return true;
           }
        }
        visited[node]=0;
        return false;
    }
  
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
        }
        
        vector<int>visited(V),current_path(V);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=dfs(i,adj,visited,current_path);
                if(ans) return true;
            }
        }
        return false;
        
    }
};