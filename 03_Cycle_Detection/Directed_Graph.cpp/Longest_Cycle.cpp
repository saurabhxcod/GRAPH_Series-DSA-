class Solution {
public:
    int maxCycleLen = -1;

    void dfs(int cycleLen, int node, vector<int>& edges, vector<int>& visited, vector<int>& current_path) {
        cycleLen++;
        visited[node] = 1;
        current_path[node] = cycleLen;
        
        int nbr = edges[node];
        if (nbr != -1) {
            if (!visited[nbr]) {
                dfs(cycleLen, nbr, edges, visited, current_path);
            } else if (current_path[nbr] != 0) {
                int currLen = current_path[node] - current_path[nbr] + 1;
                maxCycleLen = max(maxCycleLen, currLen);
            }
        }
        current_path[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0), current_path(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(0, i, edges, visited, current_path);
            }
        }
        return maxCycleLen;
    }
};
