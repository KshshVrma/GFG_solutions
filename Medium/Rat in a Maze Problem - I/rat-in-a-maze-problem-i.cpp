//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(vector<vector<int>>&m,int n,int i,int j,vector<string>&ans,string temp,
    vector<vector<int>>vis){
        if(i<0||j>=n||j<0||i>=n){
            return ;
        }
        if(i==n-1&&j==n-1){
            ans.push_back(temp);
            return ;
        }
        if(i>0&&m[i-1][j]==1&&vis[i-1][j]==0){
            vis[i-1][j]=1;
            f(m,n,i-1,j,ans,temp+'U',vis);
             vis[i-1][j]=0;
            
        }
        if(i<n-1&&m[i+1][j]==1&&vis[i+1][j]==0){
            vis[i+1][j]=1;
            f(m,n,i+1,j,ans,temp+'D',vis);
            vis[i+1][j]=0;
            
            
        }
           if(j<n-1&&m[i][j+1]==1&&vis[i][j+1]==0){
            vis[i][j+1]=1;
            f(m,n,i,j+1,ans,temp+'R',vis);
            vis[i][j+1]=0;
            
        }
           if(j>0&&m[i][j-1]==1&&vis[i][j-1]==0){
            vis[i][j-1]=1;
            f(m,n,i,j-1,ans,temp+'L',vis);
              vis[i][j-1]=1;
            
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[n-1][n-1]==0)return ans;
        if(m[0][0]==0)return ans;
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        string temp="";
        int i=0;
        int j=0;
        f(m,n,i,j,ans,temp,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends