//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int>vis(V,0);
        
        priority_queue<pair<int,int> 
        ,vector<pair<int,int>>
        ,greater<pair<int,int>>>q;
        
        
    
        int ans=0;
        q.push({0,0});
        while(!q.empty()){
            int one=q.top().first;
            int two=q.top().second;
            
            // for(auto it:adj[two]){
            //     for(int i=0;i<it.size();i++){
            //         cout<<it[i]<<" ";
            //     }
            //     cout<<endl;
            // }
            q.pop();
            if(vis[two])continue;
            vis[two]=1;
           
                ans+=one;
                
            
            
            
            for(auto it:adj[two]){
                int one=it[0];
                int two=it[1];
                if(!vis[one])
                q.push({it[1],it[0]});
            }
            
            
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends