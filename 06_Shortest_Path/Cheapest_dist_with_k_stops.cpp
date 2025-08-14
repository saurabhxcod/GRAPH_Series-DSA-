class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto &f : flights) {
            int from = f[0], to = f[1], wt = f[2];
            graph[from].push_back({to, wt});
        }

        queue<array<int, 3>> q; // {stops_taken, node, total_cost}
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [stops_taken, node, cost] = q.front();
            q.pop();

            if (stops_taken > k) continue; // limit exceeded

            for (auto &nbr_info : graph[node]) {
                int nbr = nbr_info.first;
                int wt = nbr_info.second;
                int new_cost = cost + wt;

                if (new_cost < dist[nbr]) {
                    dist[nbr] = new_cost;
                    q.push({stops_taken + 1, nbr, new_cost});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
