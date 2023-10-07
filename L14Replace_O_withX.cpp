#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int row, int col,vector<vector<char> > &ans,vector<vector<int> > &vis, vector<vector<char>> &mat , int drow[], int dcol[]  ){
        
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && vis[nrow][ncol] != 1  ){
                dfs(nrow,ncol,ans,vis,mat,drow,dcol);
            }
        }
        
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char> >ans(n,vector<char> (m,'X'));
        vector<vector<int> >vis (n,vector<int> (m,0));
        // queue<int> q;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[0][j] == 'O' && vis[0][j] != 1) {  
                    dfs(0,j,ans,vis,mat,drow,dcol);
                }
                if(mat[n-1][j] == 'O'  && vis[n-1][j] != 1 ){
                   dfs(n-1,j,ans,vis,mat,drow,dcol); 
                }
                if(mat[i][0] == 'O'  && vis[i][0] != 1){
                    dfs(i,0,ans,vis,mat,drow,dcol); 
                }
                if(mat[i][m-1] == 'O'  && vis[i][m-1] != 1){
                    dfs(i,m-1,ans,vis,mat,drow,dcol); 
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if(vis[i][j] == 1 ){
                    ans[i][j] = 'O';
                }
                
            }
        }
        return ans;
        
      
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends