// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i==0||(nums[i]!=nums[i-1]))
            for(int j=i+1;j<n;j++){
                if((j==i+1)||(nums[j]!=nums[j-1])){
                    for(int k=j+1,l=n-1;k<l;){
                        if(nums[k]+nums[l]+nums[i]+nums[j]<target){
                            k++;
                        }
                        else if(nums[k]+nums[l]+nums[i]+nums[j]>target){
                            l--;
                        } else {
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                            k++,l--;
                            while(k<l&&nums[k]==nums[k-1]&&nums[l]==nums[l+1]) k++,l--;
                            
                        }
                    }
                }
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
