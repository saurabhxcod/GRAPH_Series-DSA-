class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st) {
        visited[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }

        st.push(node); // push after all neighbors are visited (post-order)
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> visited(V, 0);
        stack<int> st;

        // Call DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Extract nodes from stack to get topological order
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};
