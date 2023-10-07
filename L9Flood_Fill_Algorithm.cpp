#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs( int inicol,vector<vector<int>> &image,vector<vector<int> > &ans, int newcolor,int row,int col,int drow[], int dcol[]){
        
        ans[row][col] = newcolor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicol && ans[nrow][ncol] != newcolor ){
                dfs(inicol,image,ans,newcolor,nrow,ncol,drow,dcol);
            }
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
       
       vector<vector<int> >ans = image;
      
       
       int inicol = image[sr][sc];
       
       int drow[] = {-1,0,+1,0};
       int dcol[] = {0,+1,0,-1};
       
       dfs(inicol,image,ans,newcolor,sr,sc,drow,dcol);
       
       return ans;
       
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends