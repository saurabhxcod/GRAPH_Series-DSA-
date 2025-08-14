class Solution {
public:
    void dfs(int node, vector<vector<int>>& forward_nbrs,
             vector<vector<int>>& backward_nbrs, vector<int>& visited,
             int& ans) {
        
        visited[node] = 1;
        
        // Forward neighbors (edge directed away from 0) – must reverse
        for (int nbr : forward_nbrs[node]) {
            if (!visited[nbr]) {
                ans += 1; // edge must be reversed
                dfs(nbr, forward_nbrs, backward_nbrs, visited, ans);
            }
        }

        // Backward neighbors (edge already towards 0) – no need to reverse
        for (int nbr : backward_nbrs[node]) {
            if (!visited[nbr]) {
                dfs(nbr, forward_nbrs, backward_nbrs, visited, ans);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward_nbrs(n), backward_nbrs(n);
        vector<int> visited(n, 0);

        for (auto& conn : connections) {
            int from = conn[0];
            int to = conn[1];
            forward_nbrs[from].push_back(to);   // Original direction
            backward_nbrs[to].push_back(from);  // Reverse direction
        }

        int ans = 0;
        dfs(0, forward_nbrs, backward_nbrs, visited, ans);
        return ans;
    }
};
