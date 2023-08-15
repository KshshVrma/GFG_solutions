//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[], vector<int>&vis, int i , int pare){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(adj, vis, it, i))return true;
            }else{
                if(it!=pare){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        
        bool temp=false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, vis, i,-1))return true;
            }
        }
        
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends