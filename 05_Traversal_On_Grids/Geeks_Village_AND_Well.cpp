// User function Template for C++

class Solution {
  public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
        // Code here
        vector<vector<int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>>result(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W') q.push({i,j});
            }
        }
        
        int counter=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int>p=q.front();
                q.pop();
                int r=p.first,co=p.second;
                for(auto &dir:direction){
                    int  nr=r+dir[0];
                    int nc=co+dir[1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && (c[nr][nc]=='H' || c[nr][nc]=='.')){
                        if(c[nr][nc]=='H'){
                            result[nr][nc]=2*counter;
                        }
                        c[nr][nc]='X';
                        q.push({nr,nc});
                        
                    }
                }
            }
            counter++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='H') result[i][j]=-1;
            }
        }
        return result;
    }
};// User function Template for C++

class Solution {
  public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
        // Code here
        vector<vector<int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>>result(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W') q.push({i,j});
            }
        }
        
        int counter=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int>p=q.front();
                q.pop();
                int r=p.first,co=p.second;
                for(auto &dir:direction){
                    int  nr=r+dir[0];
                    int nc=co+dir[1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && (c[nr][nc]=='H' || c[nr][nc]=='.')){
                        if(c[nr][nc]=='H'){
                            result[nr][nc]=2*counter;
                        }
                        c[nr][nc]='X';
                        q.push({nr,nc});
                        
                    }
                }
            }
            counter++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='H') result[i][j]=-1;
            }
        }
        return result;
    }
};