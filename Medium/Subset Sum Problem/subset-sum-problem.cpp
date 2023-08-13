//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int f(vector<int>&arr, int i, int sum, int n,vector<vector<int>>&dp){
    if(sum<0){
        return 0;
    }
    if(i==n&&sum==0){
        return 1;
    }
    if(i==n&&sum!=0){
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    
    int one=f(arr,i+1,sum-arr[i],n,dp);
    int two=f(arr,i+1,sum,n,dp);
    return dp[i][sum]=one||two;
    
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return f(arr, 0, sum, arr.size(),dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends