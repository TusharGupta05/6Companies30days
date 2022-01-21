// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum&1){
            return 0;
        }
        vector<vector<bool>> dp(N, vector<bool>(sum/2+1, false));
        if(arr[0]<=sum/2){
            dp[0][arr[0]] = true;
        }
        for(int i=1;i<N;i++){
            for(int j=1;j<sum/2;j++){
                if(dp[i-1][j]){
                    dp[i][j] = true;
                    if(j+arr[i]<=sum/2){
                        dp[i][j+arr[i]]=true;
                    }
                }
            }
            if(arr[i]<=sum/2){
                dp[i][arr[i]] = true;
            }
            if(dp[i][sum/2]){
                return 1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
