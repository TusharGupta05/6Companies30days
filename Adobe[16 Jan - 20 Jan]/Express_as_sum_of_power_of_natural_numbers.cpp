// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define mod 1000000007
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        vector<int> nums;
        for(int i=1;true;i++){
            int num = pow(i, x);
            if(num>n){
                break;
            }
            nums.push_back(num);
        }
        int sz = nums.size();
        vector<int> prev(n+1, 0);
        for(int i=0;i<sz;i++){
            vector<int> curr(n+1, 0);
            for(int j=0;j+nums[i]<=n;j++){
                curr[j+nums[i]]=prev[j]%mod;
            }
            for(int j=0;j<=n;j++){
                curr[j]=(long long)curr[j]+prev[j]%mod;
            }
            curr[nums[i]]+=1%mod;
            prev = curr;
        }
        return prev[n]%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
