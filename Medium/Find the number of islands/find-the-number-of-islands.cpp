//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>&grid,int it, int jt, int n ,int m, vector<vector<int>>&vis){
   
        vis[it][jt]=1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0&&j==0)
                    continue;
                    int row=i+it;
                    int col=j+jt;
                    if(row>=0&&row<n&&col<m&&col>=0 &&vis[row][col]==0 && 
                    grid[row][col]=='1'){
                        dfs(grid, row, col, n,m , vis);
                    }
                    
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]&& grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j , n,m  ,vis);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends