#include<iostream>
using namespace std;

int main()
{
    //n = nodes, m = edges;
    int n,m;
    cin>>n>>m;

    int adjMat[n+1][m+1];
    for(int i = 0; i<m; i++){
        // u = nodes, v = nodes
        int u,v; 
        cin>> u >> v;
        adjMat[u][v] = 1;

        // if it is undirected;
        adjMat[v][u] = 1;
    }

    return 0;
}