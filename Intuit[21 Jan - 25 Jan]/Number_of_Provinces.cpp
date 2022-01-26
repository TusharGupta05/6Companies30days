class Solution {
    int n;
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int cur){
        vis[cur] = true;
        for(int i=0; i<n; i++){
            if(isConnected[cur][i]==1&&!vis[i]){
                dfs(isConnected, vis, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected, vis, i);
            }
        }
        return ans;
    }
};
