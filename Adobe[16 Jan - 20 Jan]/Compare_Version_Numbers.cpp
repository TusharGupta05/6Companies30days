class Solution {
    int getNextNumber(string& s, int& i){
        if(s[i]=='\0'){
            return 0;
        }
        int ans=0;
        while(s[i]!='.'&&s[i]!='\0'){
            ans*=10;
            ans+=s[i]-'0';
            i++;
        }
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        while(version1[i]!='\0'||version2[j]!='\0'){
            int num1 = getNextNumber(version1, i);
            int num2 = getNextNumber(version2, j);
            if(num1<num2){
                return -1;
            }
            if(num1>num2){
                return 1;
            }
            if(version1[i]=='.'){
                i++;
            }
            if(version2[j]=='.'){
                j++;
            }
        }
        return 0;
    }
};
