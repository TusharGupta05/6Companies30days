// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s){     
    string ans="";
    int i=0, cnt;
    char ch=s[i];
    
    while(ch!='\0'){
      cnt=0;
      while(s[i]!='\0'&&ch==s[i]){
          i++;
          cnt++;
      }
      ans+=ch;
      ans+=to_string(cnt);
      ch=s[i];
    }
    return ans;
}     
 

