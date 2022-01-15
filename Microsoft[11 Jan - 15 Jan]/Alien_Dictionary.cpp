// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
		vector<unordered_set<int>> edges(K);
		vector<int> incnt(K, 0);
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < dict[i + 1].length(); j++) {
				if (j == dict[i].length()) {
					break;
				}
				if (dict[i + 1][j] != dict[i][j]) {
					if (edges[dict[i][j] - 'a'].find(dict[i + 1][j] - 'a') == edges[dict[i][j] - 'a'].end()) {
						edges[dict[i][j] - 'a'].insert(dict[i + 1][j] - 'a');
						incnt[dict[i + 1][j] - 'a']++;
					}
					break;
				}
				if (dict[i].length() > dict[i + 1].length() && j == dict[i + 1].length() - 1) {
					return "";
				}
			}
		}
		queue<int> q;
		for (int i = 0; i < K; i++) {
			if (incnt[i] == 0) {
				q.push(i);
			}
		}
		string ans = "";
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				int frnt = q.front();
				ans.push_back(frnt + 'a');
				q.pop();
				for (int child : edges[frnt]) {
					incnt[child]--;
					if (incnt[child] == 0) {
						q.push(child);
					}
				}
			}
		}
		for (int i = 0; i < K; i++) {
			if (incnt[i] > 0) {
				return "";
			}
		}
		return ans;
	}
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
