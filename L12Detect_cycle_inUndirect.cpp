#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int i,int parent,map<int,int> &visited, vector<int> adj[] ){
      
      visited[i] = 1;
      for(auto it: adj[i]){
             if(!visited[it]){
                    visited[it] = 1;
                    if(dfs(it,i,visited,adj)){
                        return true;
                    }
                }
                else if(it != parent) {
                    return true;
                    
                }
            }
            return false;
        
        
        
    }
    
    public:
    
    bool isCycle(int V, vector<int> adj[]) {
        map<int,int> visited;
        for(int i=0; i<V; i++){
           if(!visited[i]){
              if(dfs(i,-1,visited,adj)){
                  return true;
              }
           }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends