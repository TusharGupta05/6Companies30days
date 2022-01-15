// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> edges(N);
	    vector<int> done(N, 0);
	    for(const pair<int,int>& p:prerequisites){
	        edges[p.second].push_back(p.first);
	        done[p.first]++;
	    }
	    vector<int> traverse;
	    int cnt=0;
	    for(int i=0;i<N;i++){
	        if(done[i]==0){
	            traverse.push_back(i);
	            cnt++;
	        }
	    }
	    while(!traverse.empty()){
	        int back = traverse.back();
	        traverse.pop_back();
	        for(int i:edges[back]){
	            done[i]--;
	            if(done[i]==0){
	                cnt++;
	                traverse.push_back(i);
	            }
	        }
	    }
	    return cnt==N;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
