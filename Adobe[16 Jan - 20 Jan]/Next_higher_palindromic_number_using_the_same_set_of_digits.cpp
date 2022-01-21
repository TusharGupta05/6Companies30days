// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string str) { 
        string ans="";
        int n=str.length();
        vector<int> arr(10, 0);
        arr[str[n/2-1]-'0']++;
        for(int i=n/2-2;i>=0;i--){
            arr[str[i]-'0']++;
            if(str[i]>=str[i+1]){
                continue;
            } else {
                for(int j=0;j<i;j++){
                    ans+=str[j];
                }
                for(int j=str[i]-'0'+1;j<10;j++){
                    if(arr[j]>0){
                        arr[j]--;
                        ans+=j+'0';
                        int k=0;
                        while(k<10){
                            while(arr[k]>0){
                                arr[k]--;
                                ans+=k+'0';
                            }
                            k++;
                        }
                        break;
                    }
                }
                break;
            }
        }
        
        if(n&1){
            ans+=str[n/2];
        }
        for(int i=0;i<n/2;i++){
            ans+=ans[n/2-i-1];
        }
        if(ans.length()==n&&ans!=str)
        return ans;
        return "-1";
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
