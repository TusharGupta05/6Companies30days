// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    #define mod 1000000007
    int recurr(string& s, int n, int i, vector<int>& dp){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]=='0'){
            return dp[i]=0;
        }
        if((s[i]=='1'&&i<n-1)||(s[i]=='2'&&i<n-1&&s[i+1]<'7')){
            return dp[i]=(recurr(s, n, i+1, dp)+recurr(s, n, i+2, dp))%mod;
        }
        return dp[i]=recurr(s, n, i+1, dp)%mod; 
    }
	public:
		int CountWays(string& s){
		    int n=s.length();
		    vector<int> dp(n+1,-1);
		    return recurr(s, n, 0, dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
