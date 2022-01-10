// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *a, int n, int k) {
        int i=0;
        stack<int> st;
        vector<int> ans;
        while(i+k-2<n){
            int mx=0;
            for(int j=i+k-2; j>=i;j--){
                mx=max(mx, a[j]);
                st.push(mx);
            }
            mx=0;
            for(int j=i+k-1;j<min(n,i+2*k-1); j++){
                mx=max(mx, a[j]);
                if(!st.empty()){
                    ans.push_back(max(st.top(), mx));
                    st.pop();
                } else {
                    ans.push_back(mx);
                }
            }
            i+=k;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
