#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        // Path compression
        return parent[node] = find(parent[node]);
    }

    void union_sets(int a, int b) {
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA != leaderB) {
            if (rank[leaderA] < rank[leaderB]) {
                parent[leaderA] = leaderB;
                rank[leaderB] += rank[leaderA];
            } else {
                parent[leaderB] = leaderA;
                rank[leaderA] += rank[leaderB];
            }
        }
    }
};
