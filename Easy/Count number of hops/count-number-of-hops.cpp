//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;
    long long f(long long int n,vector<long long int>&dp){
      
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 4;
        }
          if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return  dp[n];
        }
        
        long long int one=f(n-1,dp)%mod;
        long long int two=f(n-2,dp)%mod;
        long long int three=f(n-3,dp)%mod;
        return dp[n]=(one+two+three)%mod;
        
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long int>dp(n+1,-1);
        return f(n,dp)%mod;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends