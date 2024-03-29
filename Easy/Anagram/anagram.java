//{ Driver Code Starts
import java.util.*;
import java.util.stream.*; 
import java.lang.*;
import java.io.*;

class GFG {
    
	public static void main (String[] args)throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0)
		{
		    String str = br.readLine();
		    String s1 = str.split(" ")[0];
		    String s2 = str.split(" ")[1];
		    
		    Solution obj = new Solution();
		    
		    if(obj.isAnagram(s1,s2))
		    {
		        System.out.println("YES");
		    }
		    else
		    {
		         System.out.println("NO");
		    }
		    
		    
		    
		}
	}
}
// } Driver Code Ends


class Solution
{    
    //Function is to check whether two strings are anagram of each other or not.
    public static boolean isAnagram(String a,String b)
    {
        if(a.length()!=b.length()){
            return false;
        }
        int[] arr=new int[26];
        int[] brr= new int[26];
        for(int i=0;i<26;i++){
            arr[i]=0;
        }
        for(int i=0;i<a.length();i++){
            char c=a.charAt(i);
            char t=b.charAt(i);
            arr[c-'a']++;
            arr[t-'a']--;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(arr[i]!=0)return false;
        }
        if(count==0){
            return true;
        }else{
            return false;
        }
        
    }
}