class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<map<char,int>, int> present;
        map<string, int> ids;
        vector<vector<string>> ans;
        for(int i=0; i<(int)string_list.size(); i++){
            map<char, int> m;
            string s = string_list[i];
            for(const char& c : s){
                m[c]++;
            }
            int isPresent = present[m];
            if(isPresent!=0){
                int id = ids[string_list[isPresent-1]];
                ans[id].push_back(s);
            } else {
                present[m] = i+1;
                ids[s] = ans.size();
                ans.push_back({s});
            }
        }
        return ans;
    }
};
