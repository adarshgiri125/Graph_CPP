#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
       vector<int> adj[V];
	   int indegree[V] = {0};
	  
       for(auto it:  prerequisites){
           adj[it[1]].push_back(it[0]);
           indegree[it[0]]++;
       }
	   
	   
	   
	   queue<int> q;
	   vector<int> ans;
	   
	   
	   
	   for(int i = 0; i < V; i++){
	       if(indegree[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       ans.push_back(node);
	       
	       for(auto i : adj[node]){
	           indegree[i]--;
	           if(indegree[i] == 0) q.push(i);
	       }
	   }
	   
	   //it is for detect cycle using BFS method (By help of TOPOSORT);
	  if (ans.size() == V){
	      return ans;
	  }
	  else{
	      return {};
	  }
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends