#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topoSort(int node, stack<int> &st, int vis[], vector< pair<int,int> > adj[]){
         vis[node] = 1;
         
         for(auto i : adj[node]){
             int it = i.first;
             if(vis[it] != 1){
                 topoSort(it,st,vis,adj);  
             }
         }
         st.push(node);
     }
     
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector< pair<int,int> > adj[N];
        for(int i = 0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        int vis[N] = {0};
        stack<int> st;
        
        for(int i = 0; i<N; i++){
            if(!vis[i]){
                topoSort(i,st,vis,adj);
            }
        }
        
        vector<int> distance(N);
        for(int i = 0; i<N; i++) distance[i] = 1e9;
        distance[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto i : adj[node]){
                int v = i.first;
                int w = i.second;
                
                if(distance[node] + w < distance[v]){
                    distance[v] = distance[node] + w;
                }
            }
        }
        for(int i = 0; i<N; i++){
            if(distance[i] == 1e9){
               distance[i] = -1;
            }
        
        } 
        return distance;
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends