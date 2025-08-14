#include <bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,vector<int>>graph,vector<int>&visited){
    cout<<node<<" ";
    visited[node]=1;
    for(int nbr:graph[node]){
        if(!visited[nbr]){
            dfs(nbr,graph,visited);
        }
    }
}
int main()
{
    vector<vector<int>> edgeList = {{0, 1}, {1, 4}, {1, 2}, {2, 3}};
    unordered_map<int,vector<int>>graph;
    int n=5;
    for(int i=0;i<n;i++){
        int a=edgeList[i][0],b=edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<<"DFS Order : ";
    vector<int>visited(5,0);
    dfs(0,graph,visited);
}