#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int row,int col, int drow[], int dcol[]){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow < n && nrow >=0 && ncol >=0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
                dfs(vis,grid,nrow,ncol,drow,dcol);
            }
        }
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
      
         int ans = 0;
         int drow[] = {-1,0,+1,0};
         int dcol[] = {0,+1,0,-1};
         for(int i = 0; i<n; i++){
             for(int j = 0; j<m; j++){
                 if(grid[i][j] == 1 && (i == 0 || i == n-1 || j == m-1 || j == 0) && vis[i][j] != 1){
                      dfs(vis,grid,i,j,drow,dcol);
                      
                 }
             }
         }
         
         for(int i = 0; i<n; i++){
             for(int j = 0; j<m; j++){
                 if(grid[i][j] == 1 && vis[i][j] != 1){
                    ans++;
                 }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends