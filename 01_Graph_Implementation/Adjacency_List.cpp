#include <bits/stdc++.h>
using namespace std;

void printGraph(unordered_map<int, vector<int>> graph)
{
    for (auto x : graph)
    {
        cout<<"Node : " <<x.first << " Neighbours : ";
        for(int node: x.second){
            cout<<node<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};
    // Map
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < edgeList.size(); i++)
    {
        int a = edgeList[i][0], b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printGraph(graph);
}