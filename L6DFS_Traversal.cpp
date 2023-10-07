#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int vis[],queue<int> &q,vector<int> adjL[],int V ){
        while(!q.empty()){
           int node = q.front();
           q.pop();
          
            for(auto i : adjL[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            
           } 
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        
         vector<int> adjL[V];
         
         for(int i = 0; i<V; i++){
             for(int j = 0; j<V; j++){
                 if(adj[i][j] == 1 && i != j){
                     adjL[i].push_back(j);
                     adjL[j].push_back(i);
                 }
             }
         }
         
         int vis[V] = {0};
         queue<int> q;
         int ans = 0;
         for(int i = 0; i<V; i++){
             if(vis[i] != 1){
                 ans++;
                 q.push(i);
                 vis[i] = 1;
                 solve(vis,q,adjL,V);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends