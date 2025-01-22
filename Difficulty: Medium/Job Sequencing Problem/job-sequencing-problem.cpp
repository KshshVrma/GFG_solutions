//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  static bool cmp(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
      return a.second>b.second;
  }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
                                  int maxi=*max_element(deadline.begin(),deadline.end()); 
                                  
        // code here
        vector<int>ans;
        int count=0;
        int sum=0;
        vector<pair<pair<int,int>,int>>vec;
        for(int i=0;i<id.size();i++){
            vec.push_back({{id[i],deadline[i]},profit[i]});
        }
        
        vector<int>jobs(maxi,-1);
        sort(vec.begin(),vec.end(), cmp);
        
        for(int i=0;i<vec.size();i++){
            int ded=vec[i].first.second;
            int pro=vec[i].second;
            
            int j=ded-1;
            while (j>=0){
                if(jobs[j]==-1){
                    jobs[j]=1;
                    sum+=pro;
                    count++;
                    break;
                }
                j--;
                
            }
            
            
        }
       ans.push_back(count);
       ans.push_back(sum);
        
        return ans;
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends