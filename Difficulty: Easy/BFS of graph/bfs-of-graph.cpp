//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<vector<int>>&adj, vector<int>&vis, int i, vector<int>&ans){
        vis[i]=1;
       
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int k=q.front();
             ans.push_back(k);
            q.pop();
            
            for(auto it: adj[k]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
            
        }
        
        
        
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        
        
        vector<int>vis(n,0);
        // for(int i=0;i<adj.size();i++){
        //     if(!vis[i]){
                bfs(adj, vis, 0,ans);
            // }
        // }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends