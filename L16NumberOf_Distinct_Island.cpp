#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid,vector< vector < int> > &vis, vector<pair<int,int> > &store,int row0, int col0 ){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0 , +1, 0};
        int dcol[] = {0, +1, 0 , -1};
        store.push_back({row - row0, col - col0});
        
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,grid,vis,store,row0,col0);
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector< vector < int> > vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int> > >st;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    vector<pair<int,int> > store;
                    dfs(i,j,grid,vis,store,i,j);
                    st.insert(store);
                }
            }
        }
        
        return st.size();
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends