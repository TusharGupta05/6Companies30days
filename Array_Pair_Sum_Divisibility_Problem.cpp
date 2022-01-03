// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()==1){
            return false;
        }
        vector<int> arr(k+1, 0);
        for(int num:nums){
            arr[num%k]++;
        }
        for(int num:nums){
            if((num%k==(k-(num%k))%k&&arr[num%k]%2==1)||(arr[num%k]!=arr[(k-(num%k))%k])){
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
