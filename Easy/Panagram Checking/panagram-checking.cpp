//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        for(int i=0;i<str.size();i++){
            if(str[i]<95){
                str[i]+=32;
            }
        }
        int arr[26]={0};
        for(int i=0;i<str.size();i++){
            arr[str[i]-97]++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                count++;
            }
        }
        return count==26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends