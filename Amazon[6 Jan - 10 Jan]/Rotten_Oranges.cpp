class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dirs({{1,0}, {0,1}, {0,-1}, {-1,0}});
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    mat[i][j]=0;
                    q.push({i,j,0});
                } else if(mat[i][j]==1) {
                    mat[i][j]=INT_MAX;
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                const vector<int> v=q.front();
                q.pop();
                for(const vector<int>& d:dirs){
                    int nx=v[0]+d[0], ny=v[1]+d[1];
                    if(nx<n&&nx>=0&&ny<m&&ny>=0&&mat[nx][ny]>v[2]+1){
                        mat[nx][ny]=v[2]+1;
                        q.push({nx, ny, v[2]+1});
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, mat[i][j]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
