#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int adjMat[n+1][m+1];
    for(int i = 0; i<m; i++){
        // u = nodes, v = nodes, w = weight;
        int u,v,w; 
        cin>> u >> v;
        adjMat[u][v] = w;

        // if it is undirected;
        adjMat[v][u] = w;
    }
    
    return 0;
}