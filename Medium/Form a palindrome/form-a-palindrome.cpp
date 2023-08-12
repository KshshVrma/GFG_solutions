//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int pal(string str){
      string s=str;
    reverse(str.begin(),str.end());
    
    if(s==str){
        return 1;
    }
    
    return 0;
  }
  
  
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

    int countMin(string str){
    //complete the function here
    // int i=str.size();
    string s=str;
    reverse(str.begin(),str.end());
    if(s==str){
        return 0;
    }
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
  int k=f(s,str,s.size()-1,str.size()-1,dp);
    
    return s.size()-k;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends