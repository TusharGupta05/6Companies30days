// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        string ans="";
        int n=s.length(), i=0;
        int mn=1;
        if(s[0]=='I'){
            mn++;
            ans+='1';
        }
        i=0;
        while(i<n){
            int ci=0, cd=0;
            while(i<n&&s[i]=='I') i++, ci++;
            while(i<n&&s[i]=='D') i++, cd++;
            for(int c=0;c<ci-1;c++){
                ans+=(mn+c+'0');
            }
            mn+=max(0,ci-1);
            ans+=(mn+cd+'0');
            int cc=cd;
            for(int c=cd-1;c>=0;c--){
                ans+=(mn+c+'0');
            }
            mn+=cc+1;
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
