// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    string solve(string& s, int n, int& i){
        string ans = "";
    
        while(i<n){
            while(i<n&&s[i]>='a'&&s[i]<='z'){
                ans+=s[i];
                i++;
            }
            if(i==n){
                return ans;
            }
            int sz=0;
            while(i<n&&s[i]>='0'&&s[i]<='9'){
                sz*=10;
                sz+=s[i]-'0';
                i++;
            }
            if(i==n){
                return ans;
            }
            if(s[i]=='['){
                i++;
                string mid = solve(s, n, i);
                while(sz--){
                    ans+=mid;
                }
            } else if(s[i]==']'){
                i++;
                return ans;
            }
        }
        return ans;
    }
public:
    string decodedString(string s){
        int i=0;
        return solve(s, s.length(), i);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
