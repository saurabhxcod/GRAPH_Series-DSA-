class Solution {
  public:
    
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &current_path) {
        visited[node] = 1;
        current_path[node] = 1;

        for(int nbr : adj[node]) {
            if(!visited[nbr]) {
                if(dfs(nbr, adj, visited, current_path)) return true;
            }
            else if(current_path[nbr] == 1) {
                // A cycle detected
                return true;
            }
        }

        current_path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), current_path(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, current_path);
            }
        }
        
        vector<int> res;
        for(int i = 0; i < V; i++) {
            if(current_path[i] == 0) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
