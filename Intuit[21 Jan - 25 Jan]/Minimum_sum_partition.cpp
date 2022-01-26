// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    vector<bool> dp((sum+1)/2, false);
	    int ans=abs(arr[0]-(sum-arr[0]));
	    if(arr[0]<=(sum+1)/2){
	        dp[arr[0]] = true;
	    }
	    for(int i=1;i<n;i++){
	        ans = min(ans, abs(arr[i]-(sum-arr[i])));
	        vector<bool> cur((sum+1)/2, false);
	        for(int j=0;j<=(sum+1)/2;j++){
	            if(dp[j]){
	                cur[j] = true;
	                if(j+arr[i]<=(sum+1)/2){
	                    cur[j+arr[i]] = true;
	                }
	                ans=min(ans, abs(j+arr[i]-(sum-j-arr[i])));
	            }
	        }
	        if(arr[i]<=(sum+1)/2){
	            cur[arr[i]] = true;
	        }
	        dp = cur;
	    }
	    return ans;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
