// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        vector<pair<int, int>> v;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				v.push_back({arr[i][j], i});
			}
		}
		sort(v.begin(), v.end());
		queue<pair<int,int>> q;
		int count[k];
		memset(count, 0, sizeof(count));
		pair<int, int> ans = {0, 1000000};
		int cnt = 0, idx = 0;
		while (idx < n * k) {
		    int val, i;
			tie(val, i) = v[idx];
			q.push(v[idx]);
			count[i]++;
			if(count[i]==1){
			    cnt++;
			}
			int val1, j;
		    tie(val1, j) = q.front();
			while(cnt==k&&count[j]>0){
			    count[j]--;
			    if(count[j]==0){
			        cnt--;
			    }
			    q.pop();
			    if(val-val1<ans.second-ans.first){
			        ans = {val1, val};
			    }
			    tie(val1, j) = q.front();
			}
			idx++;
		}
		return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
