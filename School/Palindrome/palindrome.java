//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            String ans = ob.is_palindrome(n);
            System.out.println(ans);
        }
    }
}


// } Driver Code Ends


//User function Template for Java

class Solution
{
    public String is_palindrome(int n)
    {
        // Code here
        ArrayList<Character>arr=new ArrayList<Character>();
        while(n>0){
            int wow=n%10;
            char c=(char)(wow+'0');
            arr.add(c);
            n=n/10;
        }
        int i=0;
        int j=arr.size()-1;
        int flag=0;
        while(i<j){
            if(arr.get(i)!=arr.get(j))flag=1;
            i++;
            j--;
        }
        if(flag==1){
            
            return "No";
        }else{
            return "Yes";
        }
        
    }
}