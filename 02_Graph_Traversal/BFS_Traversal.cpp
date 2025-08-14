#include <bits/stdc++.h>
using namespace std;

void bfs(int src, unordered_map<int, vector<int>>& graph) {
    queue<int> q;
    vector<int> visited(6, 0);
    
    q.push(src);
    visited[src] = 1;
    
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        cout << f << " ";  
        
        for (int nbr : graph[f]) {
            if (!visited[nbr]) {
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
}

int main() {
    vector<vector<int>> edgeList = {{0, 1}, {1, 4}, {1, 2}, {2, 3}};
    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < edgeList.size(); i++) {
        int a = edgeList[i][0];  
        int b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);   
    }

    cout << "BFS Order: ";
    bfs(0, graph);
}
