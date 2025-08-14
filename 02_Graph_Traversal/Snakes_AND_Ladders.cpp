#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> connection(n * n + 1, -1);

        // Step 1: Flatten the board into a 1D mapping (cell -> jump destination)
        int node = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1) {
                        connection[node] = board[i][j];
                    }
                    node++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1) {
                        connection[node] = board[i][j];
                    }
                    node++;
                }
            }
            leftToRight = !leftToRight;
        }

        // Step 2: Build graph of moves from each cell using dice rolls
        unordered_map<int, vector<int>> graph;
        for (int i = 1; i <= n * n - 1; i++) {
            for (int dice = 1; dice <= 6; dice++) {
                int next = i + dice;
                if (next <= n * n) {
                    // If there's a snake or ladder, follow it
                    if (connection[next] != -1) {
                        graph[i].push_back(connection[next]);
                    } else {
                        graph[i].push_back(next);
                    }
                }
            }
        }

        // Step 3: BFS to find the minimum number of moves
        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int pos = q.front();
                q.pop();
                if (pos == n * n) return level; // Reached destination

                for (int neighbor : graph[pos]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            level++;
        }

        return -1; // Not reachable
    }
};
