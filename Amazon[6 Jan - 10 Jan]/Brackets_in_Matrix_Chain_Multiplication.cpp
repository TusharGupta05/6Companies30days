// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    long long dp[501][501];
    int bracket[501][501];
    void print(int i,int j,string &ans) {   
        if(i>j)
        return;
        if(i==j-1 or i==j) {
            ans+='A'+j-1;
            return;
        }
        ans+='(';
        print(i,bracket[i][j],ans);
        print(bracket[i][j],j,ans);
        ans+=')';
    }
    long long recurr(int i,int j,int arr[]) {
        if(i==j-1 or i==j) {
            bracket[i][j]=j;
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long mn=1e18;
        int next=0;
        for(int k=i+1;k<j;k++) {
            long long val=recurr(i,k,arr)+recurr(k,j,arr)+arr[i]*arr[k]*arr[j];
            if(val<=mn) {
                mn=val;
                next=k;
            }
        }   
        bracket[i][j]=next;
        return dp[i][j]=mn;
    }
    public:
    string matrixChainOrder(int p[], int n){
        memset(dp,-1,sizeof dp);
        long long x=recurr(0,n-1,p);
        string ans="";
        print(0,n-1,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
