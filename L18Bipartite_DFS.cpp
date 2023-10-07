#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool check(int parent,int col, int color[],vector<int> adj[], int V ){
        
            color[parent] = col;
          
            for(auto i : adj[parent]){
                if(color[i] == -1){
                   
                    if(check(i,!col,color,adj,V) == false){
                        return false;
                    }
                    
                }
                else if(color[i] == col){
                    return false;
                }   
            }
        
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	  
	   int color[V]; 
	   memset(color, -1, sizeof(color));
	   
	   for(int i = 0; i<V; i++){
	       if(color[i] == -1){
	          
	           if(check(i,0,color,adj,V) == false){
	               return false;
	           }
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends