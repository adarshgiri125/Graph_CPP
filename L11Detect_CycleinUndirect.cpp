#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    bool ans = false;

    for (int i = 0; i < V; i++) {
        if (vis[i] != 1) {
            queue<pair<int, int>> q;
            q.push({i, -1}); // Change here, pushing {i, -1} as the starting node for BFS
            vis[i] = 1;

            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto neighbor : adj[node]) {
                    if (vis[neighbor] != 1) {
                        vis[neighbor] = 1;
                        q.push({neighbor, node});
                    } else if (parent != neighbor) {
                        ans = true;
                        break;
                    }
                }

                if (ans)
                    break;
            }
        }
        
        if (ans)
            break;
    }

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