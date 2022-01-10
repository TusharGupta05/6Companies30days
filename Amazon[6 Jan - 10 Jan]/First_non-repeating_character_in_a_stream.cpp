// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans="";
		    int cnt[26]={0};
		    deque<char> order;
		    for(int i=0; i<A.length();i++){
		        int ch=A[i]-'a';
		        cnt[ch]++;
		        if(cnt[ch]==1){
		            order.push_back(A[i]);
		        }
	            bool flag=false;
	            for(char c:order){
	                if(cnt[c-'a']==1){
	                    ans.push_back(c);
	                    flag=true;
	                    break;
	                } else {
	                    order.pop_front();
	                }
	            }
	            if(!flag){
                    ans.push_back('#');
	            }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
