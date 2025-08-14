// User Function Template

//For Postive Edge Weighted Graph
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Convert edge list to adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            // If undirected graph, uncomment the line below
            // adj[v].push_back({u, w});
        }

        // Step 2: Initialize distance vector and priority queue
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        // Step 3: Dijkstra's main loop
        while (!pq.empty()) {
            auto [curr_dist, node] = pq.top();
            pq.pop();

            for (auto &nbr_info : adj[node]) {
                int nbr = nbr_info.first;
                int weight = nbr_info.second;

                int prev_dist = dist[nbr];
                int new_dist = curr_dist + weight;

                if (new_dist < prev_dist) {
                    dist[nbr] = new_dist;
                    pq.push({new_dist, nbr});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
