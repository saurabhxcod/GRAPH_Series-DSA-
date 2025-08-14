class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0;
        vector<vector<int>> graph(n), cnt(n, vector<int>(26));
        vector<int> indegree(n, 0);

        // Build the graph
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // Topological sort using Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int processed = 0;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            processed++;

            // Update the color count of current node
            cnt[f][colors[f] - 'a']++;
            ans = max(ans, cnt[f][colors[f] - 'a']);

            // Traverse neighbors
            for (auto nbr : graph[f]) {
                // Update color counts for the neighbor
                for (int j = 0; j < 26; j++) {
                    cnt[nbr][j] = max(cnt[nbr][j], cnt[f][j]);
                }

                // Decrement indegree and push if zero
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }

        // If all nodes are processed, return the answer. Otherwise, cycle exists.
        return (processed == n) ? ans : -1;
    }
};
