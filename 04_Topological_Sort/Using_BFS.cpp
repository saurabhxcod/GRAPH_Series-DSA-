//Kahn's Algorithm
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i < edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
        }
        
        vector<int>indegree(V,0),ans;
        //compute the indegree and fill
        for(int i=0;i<V;i++){
            for(int &x:adj[i])
            indegree[x]+=1;
        }
        
        queue<int>q;
        
        //check if the indegree is zero then push it to queue
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        
        //aftter pushing check for its nbr and reduce in the indegree
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int x : adj[f]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        return ans;
    }
};