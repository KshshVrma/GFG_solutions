//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
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
  
  
  string p(string s,string b,int n,int m){
      
      int i=0;
      string temp="";
      int j=0;
      while(i<n&&j<m){
          if(b[j]==s[i]){
              i++;
              j++;
          }
          else{
            //  while(i<n&&j<m && b[j]!=s[i]){
                  i++;
            //   }
          }
          
      }
      if(j==m){
          return b;
      }
      return "";
  }
  int fun(string a,string b){
     int flag=0;
     vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));
     string k=p(a,b,a.size(),b.size());
      if(k==b)return 1;
      return 0;
  }
  static bool q(string a, string b){
    //   if(a.size()==b.size()){
    //       return a<b;
    //   }
      return a.size()<b.size();
  }
    string findLongestWord(string S, vector<string> d) {
        // code here
        sort(d.begin(),d.end(),q);
        vector<string>r;
        int wow=9;
        for(int i=d.size()-1;i>=0;i--){
            if(fun(S,d[i])){
                // return d[i];
                wow=max(wow,int(d[i].size()));
               r.push_back(d[i]);
            }
        }
        // return r[0];
        vector<string>po;
        for(int i=0;i<r.size();i++){
            if(r[i].size()==wow){
                po.push_back(r[i]);
            }
        }
        sort(po.begin(),po.end());
        return r[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++) cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends