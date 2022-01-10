// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> dp;
    int recurr(int a[], int n, int k, int i){
        if(k<=0){
            return 0;
        }
        if(i==n){
            if(k%2==1){
                return -1;
            }
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        if(k%2==0){
            return dp[i][k]=max(recurr(a, n, k, i+1), recurr(a, n, k-1, i+1)-a[i]);
        }
        int val1=recurr(a, n, k, i+1);
        if(val1==-1){
            return dp[i][k]=recurr(a, n, k-1, i+1)+a[i];
        }
        return dp[i][k]=max(val1, recurr(a, n, k-1, i+1)+a[i]);
    }
  public:
    int maxProfit(int K, int N, int A[]) {
        K*=2;
        dp=vector<vector<int>>(N, vector<int>(K+1,-1));
        return recurr(A, N, K, 0);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
