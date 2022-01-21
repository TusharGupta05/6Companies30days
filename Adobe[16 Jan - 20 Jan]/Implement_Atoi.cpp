// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans=0;
        bool neg=false;
        for(int i=0;i<str.length();i++){
            if(i==0&&str[i]=='-'){
                neg=true;
                continue;
            }
            char c = str[i];
            if(c>='0'&&c<='9'){
                ans*=10;
                ans+=(c-'0');
                continue;
            }
            return -1;
        }
        if(neg){
            return -ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
