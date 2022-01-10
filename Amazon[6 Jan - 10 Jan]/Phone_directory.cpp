// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Trie{
    class TrieNode{
        public:
        TrieNode* ch[26];
        vector<int> idxs;
    };
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string& s, int i){
        TrieNode* temp = root;
        for(char ch:s){
            root->idxs.push_back(i);
            if(root->ch[ch-'a']==NULL){
                root->ch[ch-'a'] = new TrieNode();
            }
            root = root->ch[ch-'a'];
        }
        root->idxs.push_back(i);
        root = temp;
    }
    vector<vector<int>> search(string& query){
        vector<vector<int>> ans(query.length());
        for(int i=0;i<query.length();i++){
            if(root->ch[query[i]-'a']==NULL){
                break;
            }
            root = root->ch[query[i]-'a'];
            ans[i] = root->idxs;
        }
        return ans;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort(contact, contact+n);
        Trie* trie = new Trie();
        for(int i=0; i<n; i++){
            if(i==0||(i>0&&contact[i]!=contact[i-1]))
            trie->insert(contact[i], i);
        }
        vector<vector<string>> ans(s.length());
        int j=0;
        for(const vector<int>& v:trie->search(s)){
            for(const int& i:v){
                ans[j].push_back(contact[i]);
            }
            if(v.empty()){
                ans[j].push_back("0");
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
