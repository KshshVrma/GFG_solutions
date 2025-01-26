//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
        return a.second<b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int ans=0;
        vector<pair<pair<int,int>,int>> vec;
        for(int i=0;i<start.size();i++){
            pair<int,int> x={start[i],i};
            vec.push_back({x, end[i]});
        }
        
        sort(vec.begin(),vec.end(), cmp);
        
        if (vec.size()==0){
            return 0;
        }
        
        int currans=1;
        int curr=vec[0].second;
        for(int i=1;i<vec.size();i++){
            if(vec[i].first.first>curr){
                currans+=1;
                curr=vec[i].second;
            }
        }
        return currans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends