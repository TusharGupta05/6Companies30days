class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n, 0);
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0&&grid[i][j]==0;j--){
                cnt[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(cnt[i]<n-i-1){
                for(int j=i+1;j<n;j++){
                    if(cnt[j]>=n-i-1){
                        for(int k=j;k>i;k--){
                            swap(cnt[k], cnt[k-1]);
                            ans++;
                        }
                        break;
                    } else if(j==n-1){
                        return -1;
                    }
                }
            }
        }
        return ans;
    }
};
