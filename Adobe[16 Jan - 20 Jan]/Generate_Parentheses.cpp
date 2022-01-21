// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    vector<string> ans;
    void backtrack(int open, int total, int close, string& str){
        if(open==total){
            if(close==total){
                ans.push_back(str);
                return;
            }
            str+=')';
            backtrack(open, total, close+1, str);
            str.pop_back();
        } else if(open>close){
            str+='(';
            backtrack(open+1, total, close, str);
            str.pop_back();
            str+=')';
            backtrack(open, total, close+1, str);
            str.pop_back();
        } else {
            str+='(';
            backtrack(open+1, total, close, str);
            str.pop_back();
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        string str="";
        backtrack(0, n, 0, str);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
