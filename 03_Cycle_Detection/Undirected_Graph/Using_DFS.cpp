class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int parent) {
        visited[node] = 1;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, adj, visited, node)) return true;
            } 
            else if (nbr != parent) {
                return true; // Cycle found
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list for 0-based indexing
        vector<vector<int>> adj(V);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1)) return true;
            }
        }

        return false;
    }
};
