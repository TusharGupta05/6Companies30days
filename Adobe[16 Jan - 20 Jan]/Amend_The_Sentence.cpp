// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        string ans="";
        if(s[0]>='a'){
            ans+=s[0];
        } else {
            ans+=s[0]+32;
        }
        for(int i=1;s[i]!='\0';i++){
            if(s[i]>='a'){
                ans+=s[i];
            } else {
                ans+=' ';
                ans+=s[i]+32;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
