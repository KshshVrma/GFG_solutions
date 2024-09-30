//{ Driver Code Starts
//Initial Template for Java


import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.evenlyDivides(N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution{
    static int evenlyDivides(int N){
        // code here
        int ans=0;
        
        ArrayList<Integer> arr= new ArrayList<Integer>();
        int dup=N;
        
        while(dup!=0){
            if(dup<10){
                arr.add(dup);
                break;
            }
            else{
                int k=dup%10;
                if(k==0){dup/=10;continue;}
                dup/=10;
                arr.add(k);
            }
        }
        
        for(int i=0;i<arr.size();i++){
            if(N%arr.get(i)==0){
                ans++;
            }
        }
        return ans;
    }
}