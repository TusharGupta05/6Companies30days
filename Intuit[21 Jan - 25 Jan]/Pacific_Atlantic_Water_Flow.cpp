class Solution {
    int n, m;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& heights, vector<vector<vector<int>>>& dp, int x, int y, int k){
        for(const vector<int>& d: dirs){
            int nx = x+d[0];
            int ny = y+d[1];
            if(nx<n && nx >= 0 && ny < m && ny >= 0 && heights[nx][ny] >= heights[x][y] && dp[nx][ny][k]==-1){
                dp[nx][ny][k] = 1;
                dfs(heights, dp, nx, ny, k);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        for(int i=0;i<m;i++){
            dp[0][i][0] = 1;
            dp[n-1][i][1] = 1;
            dfs(heights, dp, 0, i, 0);
            dfs(heights, dp, n-1, i, 1);
        }
        for(int i=0;i<n;i++){
            dp[i][0][0] = 1;
            dp[i][m-1][1] = 1;
            dfs(heights, dp, i, 0, 0);
            dfs(heights, dp, i, m-1, 1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j][0] == 1 && dp[i][j][1] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
