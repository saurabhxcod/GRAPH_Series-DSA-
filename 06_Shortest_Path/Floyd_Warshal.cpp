// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int V=dist.size();
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(dist[i][k]==1e8 || dist[k][j]==1e8) continue;
                    int dist_via_k=dist[i][k]+dist[k][j];
                    if(dist_via_k<dist[i][j]){
                        dist[i][j]=dist_via_k;
                    }
                }
            }
        }
    }
};