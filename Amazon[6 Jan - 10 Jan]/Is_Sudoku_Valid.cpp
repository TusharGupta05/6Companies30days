// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        vector<int> rows(9,0), cols(9,0), submatrices(9,0);
        vector<int> pows(9,0);
        pows[0]=1;
        for(int i=1;i<9;i++){
            pows[i]=(pows[i-1]<<1);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]!=0){
                    if((rows[i]&pows[mat[i][j]-1])==pows[mat[i][j]-1]){
                        return 0;
                    } else {
                        rows[i]|=pows[mat[i][j]-1];
                    }
                    if((cols[j]&pows[mat[i][j]-1])==pows[mat[i][j]-1]){
                        return 0;
                    } else {
                        cols[j]|=pows[mat[i][j]-1];
                    }
                    if((submatrices[(i/3)*3+(j/3)]&pows[mat[i][j]-1])==pows[mat[i][j]-1]){
                        return 0;
                    } else {
                        submatrices[(i/3)*3+(j/3)]|=pows[mat[i][j]-1];
                    }
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
