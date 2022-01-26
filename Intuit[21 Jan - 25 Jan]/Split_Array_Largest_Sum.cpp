class Solution {
        vector<vector<int>> dp;
        int recurr ( vector<int>& nums, int m, int i ) {
            if ( i == nums.size() ) {
                if ( m == 0 ) {
                    return 0;
                }
                return INT_MAX;
            }
            if ( m == 0 ) {
                return INT_MAX;
            }
            if ( dp[i][m] != -1 ) {
                return dp[i][m];
            }
            if ( m == 1 ) {
                return dp[i][m] = accumulate ( nums.begin() + i, nums.end(), 0 );
            }
            int sum = 0, mx = INT_MAX;
            for ( int j = i; j < nums.size(); j++ ) {
                sum += nums[j];
                mx = min ( mx, max ( sum, recurr ( nums, m - 1, j + 1 ) ) );
            }
            return dp[i][m] = mx;
        }
    public:
        int splitArray ( vector<int>& nums, int m ) {
            dp = vector<vector<int>> ( nums.size(), vector<int> ( m + 1, -1 ) );
            return recurr ( nums, m, 0 );
        }
};
