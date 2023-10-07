#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(vector<int> &vis,vector<int> &path,vector<int> adj[],int node){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto i : adj[node]){
            if(vis[i] != 1){
                if(dfs(vis,path,adj,i) == true){
                    return true;
                }
                path[i] = 0;
            }
            else if(vis[i] == 1 && path[i] == 1){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
      
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                if(dfs(vis,path,adj,i)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends