class Solution {
public:

    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int node){
        visited[node]=true;
        for(int i:adj[node]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>>adj(n);
        for(auto &v:connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool>visited(n,false);
        int cmp=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                cmp++;
            }
        }
        return cmp-1;
    }
};