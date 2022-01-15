// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int row, int col) 
    {
        int n = row*col;
        vector<int> ans(n);
        int i = 0;
        int top = 0, bottom = row-1, left = 0, right = col-1;
        while(i<n){
            for(int j = left; j <= right&&i<n; j++, i++){
                ans[i] = matrix[top][j];
            }
            top++;
            for(int j = top; j<=bottom&&i<n; j++, i++){
                ans[i] = matrix[j][right];
            }
            right--;
            for(int j = right; j >= left&&i<n; j--, i++){
                ans[i] = matrix[bottom][j];
            }
            bottom--;
            for(int j=bottom; j>=top&&i<n;j--, i++){
                ans[i] = matrix[j][left];
            }
            left++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
