class Solution {
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = -1;
        vector<pair<int,int>> v;
        queue<pair<int,int>> q;
        // vector<vector<int>> distances(n, vector<int>(n, -1));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        bool first = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*n||q.size()==0){
            return -1;
        }
        int dist=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> frnt = q.front();
                q.pop();
                for(const vector<int>& d:dirs){
                    int nx = frnt.first+d[0], ny = frnt.second+d[1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            ans = dist;
            dist++;
        }
        return ans;
    }
};
