// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<vector<int>> dp;
    vector<int> prefs;
    int recurr(vector<int>& a, int n, int i, int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return a[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = max(a[i]+prefs[j+1]-prefs[i+1]-recurr(a, n, i+1, j), a[j]+prefs[j]-prefs[i]-recurr(a, n, i, j-1));
    }
public:
    int maxCoins(vector<int>&a,int n)
    {
	    dp = vector<vector<int>>(n, vector<int>(n, -1));
        prefs = vector<int>(n+1, 0);
        prefs[0] = 0;
        for(int i=0;i<n;i++){
            prefs[i+1]=prefs[i]+a[i];
        }
        return recurr(a, n, 0, n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
