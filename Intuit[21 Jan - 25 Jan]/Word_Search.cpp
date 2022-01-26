// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int n,m;
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool dfs(int i, int j, int k, vector<vector<char>>& board, vector<vector<bool>>& vis, string& word){
        if(word[k]=='\0'){
            return true;
        }
        vis[i][j]=true;
        for(const vector<int>& d:dirs){
            int nx = i+d[0], ny = j+d[1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]==word[k]&&!vis[nx][ny]){
                if(dfs(nx, ny, k+1, board, vis, word)){
                    return true;
                }
            }
        }
        vis[i][j]=false;
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs( i, j, 1, board, vis, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
