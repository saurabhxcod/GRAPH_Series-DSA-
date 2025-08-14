#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent) {
        queue<int> q;
        visited[start] = 1;
        parent[start] = -1;  // root has no parent
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    parent[nbr] = node;
                    q.push(nbr);
                }
                else if (nbr != parent[node]) {
                    // If already visited and not the parent -> cycle
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        vector<int> visited(V, 0);
        vector<int> parent(V, -1);  // Store parent of each node

        // In case the graph is disconnected
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (bfs(i, adj, visited, parent)) return true;
            }
        }

        return false;
    }
};
