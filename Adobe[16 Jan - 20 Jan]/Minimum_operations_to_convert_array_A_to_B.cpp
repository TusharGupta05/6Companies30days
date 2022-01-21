// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int n = 100000;
    int st[200001]={0};
    void modify(int val, int i){
        for(st[i+=n]=val;i>>=1;){
            st[i] = max(st[i<<1], st[i<<1|1]);
        }
    }
    int query(int i, int j){
        int ans=0;
        for(i+=n, j+=n; i<j; i>>=1, j>>=1){
            if(i&1){ans=max(ans, st[i++]);}
            if(j&1){ans=max(ans, st[--j]);}
        }
        return ans;
    }
    
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        map<int,int> m;
        for(int i=0;i<M;i++){
            m[B[i]]++;
        }
        int ans=0;
        for(int i=0;i<N;i++){
            if(m[A[i]]){
                int res = max( st[A[i]+n-1], query(0, A[i]-1)+1);
                modify(res, A[i]-1);
                ans=max(ans, res);
            }
        }
        return M+N-2*ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
