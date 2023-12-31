//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int arr[],int prev,int i,int n,vector<vector<int>>&dp){
	    if(i>=n){
	        return 0;
	    }
	    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
	    int one=-1e6,two=-1e6;
	    if(prev==-1||arr[prev]<arr[i]){
	        one=arr[i]+f(arr,i,i+1,n,dp);
	    }
	    two=f(arr,prev,i+1,n,dp);
	    return dp[i][prev+1]=max(one,two);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int prev=-1;
	    int i=0;
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	   return f(arr,prev,i,n,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends