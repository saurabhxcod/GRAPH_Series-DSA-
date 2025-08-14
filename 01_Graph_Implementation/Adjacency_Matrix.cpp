#include <bits/stdc++.h>
using namespace std;

void printGraph( vector<vector<int>>adjacencyMatrix){
    for(int i=1;i<=4;i++){
        cout<<"Node :"<<i<<" Neighbours: ";
        for(int j=1;j<=4;j++){
            if(adjacencyMatrix[i][j]==1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>>edgeList={{1,2},{2,3},{3,4},{4,2},{1,3}};
    vector<vector<int>>adjacencyMatrix(5,vector<int>(5,0));
    for(int i=0;i<edgeList.size();i++){
        int a=edgeList[i][0] , b=edgeList[i][1];
        adjacencyMatrix[a][b]=1;
        adjacencyMatrix[b][a]=1;
    }

    printGraph(adjacencyMatrix);

}