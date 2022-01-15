// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int bfs(vector<vector<int>>& grid, int n, int m, vector<vector<bool>>& vis, int i, int j){
        int ans=0;
        vector<vector<int>> dirs({{1,0}, {1,1}, {0,1}, {-1,1}, {1,-1}, {-1,-1}, {-1,0}, {0,-1}});
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                ans++;
                for(const vector<int>& d:dirs){
                    int nx=x+d[0], ny=y+d[1];
                    if(nx<n&&nx>=0&&ny<m&&ny>=0&&!vis[nx][ny]&&grid[nx][ny]==1){
                        vis[nx][ny]=true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    ans=max(ans, bfs(grid, n, m, vis, i, j));
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
