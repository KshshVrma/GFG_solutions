//{ Driver Code Starts
import java.util.*;
class PalindromicArray{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0)
		{
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0 ;i < n; i++)
				a[i]=sc.nextInt();
			GfG g = new GfG();
			System.out.println(g.palinArray(a , n));
		}
	}
}
// } Driver Code Ends


/*Complete the Function below*/
class GfG
{public static int f(int a){
    int k=a;
    int count=0;
    while(k>0){
        k/=10;
        count++;
    }
    int[] arr;
    arr=new int[count];
    int p=0;
    while(a>0){
        arr[p++]=a%10;
        a/=10;
    }
    
    int i=0;
    int j=count-1;
    while(i<j){
        if(arr[i]!=arr[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
	public static int palinArray(int[] a, int n)
           {
                  //add code here.
                  int flag=0;
                  for(int i=0;i<n;i++){
                      if(f(a[i])==0){
                          return 0;
                      }
                  }
                  return 1;
           }
}