#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void solve( vector<int> &ans, queue<int> &store,int vis[], vector<int> adj[],int V){
        while(!store.empty()){
            int node = store.front();
            store.pop();
            ans.push_back(node);
            
               
               for(auto i : adj[node]){
                   if(!vis[i]){
                     vis[i] = 1;
                     store.push(i);
                   
               }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        queue<int> store;
        vector<int> ans;
        store.push(0);
        vis[0] = 1;
        solve(ans,store,vis,adj,V);
        
        return ans;
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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends