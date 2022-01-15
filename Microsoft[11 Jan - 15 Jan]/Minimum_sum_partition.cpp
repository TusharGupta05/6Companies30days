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
	    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	    int ans=abs(arr[0]-(sum-arr[0]));
	    dp[0][arr[0]] = true;
	    for(int i=1;i<n;i++){
	        ans = min(ans, abs(arr[i]-(sum-arr[i])));
	        for(int j=0;j<=sum;j++){
	            if(dp[i-1][j]){
	                dp[i][j] = true;
	                dp[i][j+arr[i]] = true;
	                ans=min(ans, abs(j+arr[i]-(sum-j-arr[i])));
	            }
	        }
	        dp[i][arr[i]] = true;
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
