//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int f(string &s,string &t, int i ,int j,vector<vector<int>>&dp){
      if(i<0||j<0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int one=0;
      if(s[i]==t[j]){
          one=1+f(s,t,i-1,j-1,dp);
      }
      one=max(one,f(s,t,i-1,j,dp));
      one=max(one,f(s,t,i,j-1,dp));
      return dp[i][j]=one;
  }
    int minimumNumberOfDeletions(string S) { 
        // code here
        string s=S;
        string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        int k=f(s,t,s.size()-1,t.size()-1,dp);
        return s.size()-k;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends