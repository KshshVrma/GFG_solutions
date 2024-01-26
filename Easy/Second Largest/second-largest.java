//{ Driver Code Starts
//Initial Template for Java



import java.util.stream.Collectors; 
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().print2largest(arr, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    int print2largest(int arr[], int n) {
        // code here
        // PriorityQueue<Integer> pq=new PriorityQueue<Integer>(Collections.reverseOrder());
        // for(int i=0;i<n;i++){
        //     pq.add(arr[i]);
        // }
        // pq.poll();
        // return pq.poll();
        TreeSet<Integer>st=new TreeSet<Integer>(Collections.reverseOrder());
        for(int i=0;i<n;i++){
            st.add(arr[i]);
        }
        if(st.size()<2)return -1;
        ArrayList<Integer>vec=new ArrayList<Integer>(st);
        return vec.get(1);
    }
}