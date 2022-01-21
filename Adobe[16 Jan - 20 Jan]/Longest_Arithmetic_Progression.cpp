// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int dfs(int tar, int diff, vector<int>& present, vector<vector<int>>& dp){
        if(tar>10000){
            return 0;
        }
        if(present[tar]!=-1){
            if(dp[present[tar]][diff]!=-1){
                return dp[present[tar]][diff];
            }
            return dp[present[tar]][diff]=1+dfs(tar+diff, diff, present, dp);
        }
        return 0;
    }
public:
    int lengthOfLongestAP(int a[], int n) {
        vector<int> present(10001, -1);
        for(int i=0;i<n;i++){
            present[a[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(10000, -1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=1;a[i]+j<=10000;j++){
                ans=max(ans, 1+dfs(a[i]+j, j, present, dp));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
