//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>vec(n+1, -1);
        for(auto it: arr){
            
           
            vec[it-1]=1;
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]==-1){
                return i+1;
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends