// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++
#define mod 1000000007
class Solution
{
    int dp[1001][1001];
    int recurr(int N, int K, int i){
        if(N==0){
            return 1;
        }
        if(dp[N][i]!=-1){
            return dp[N][i];
        }
        if(i<K){
            return dp[N][i] = (21LL*recurr(N-1, K, 0)+5LL*recurr(N-1, K, i+1))%mod;
        }
        if(i==K){
            return dp[N][i] = 21LL*recurr(N-1, K, 0)%mod;
        }
    }
    public:
    int kvowelwords(int N, int K) {
        memset(dp, -1, sizeof(dp));
        return recurr(N, K, 0);
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
