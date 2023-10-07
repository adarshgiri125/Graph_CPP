#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool dfs(vector<int> &vis,vector<int> &path,vector<int> adj[],int node,vector<int> &check){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto i : adj[node]){
            if(vis[i] != 1){
                if(dfs(vis,path,adj,i,check) == true){
                    check[node] = 0;
                    return true;
                }
                path[i] = 0;
            }
            else if(vis[i] == 1 && path[i] == 1){
                check[i] = 0;
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
      
  public:
    // Function to detect cycle in a directed graph.
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        
        vector<int> ans;
        
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                dfs(vis,path,adj,i,check);
                 
            }
        }
        
        for(int i = 0; i<V; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends