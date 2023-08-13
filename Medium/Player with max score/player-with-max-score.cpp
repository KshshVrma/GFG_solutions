//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
long long int f(int arr[],int i, int j,int N,vector<vector<long long int>>&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    long long int one=arr[i]+min(f(arr,i+2,j,N,dp),f(arr,i+1,j-1,N,dp));
    long long int two=arr[j]+min(f(arr,i,j-2,N,dp),f(arr,i+1,j-1,N,dp));
    return dp[i][j]=max(one,two);
    
}
    bool is1winner(int N,int arr[]) {

        
        // code here
        int i=0;int j=N-1;
       long long int sum=0;
        vector<vector<long long int>>dp(N,vector<long long int>(N,-1));
        for(int k=0;k<N;k++)sum+=arr[k];
      long long int tum=f(arr,i,j,N,dp);
       if(tum>(sum-tum)){
           return 1;
       }
       return 0;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends