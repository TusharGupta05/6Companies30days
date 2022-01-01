class Solution {
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    public:
    string gcdOfStrings(string str1, string str2) {
        int g = gcd(str1.length(), str2.length());
        for(int i=g,j=0;i<str1.length();i++,j++){
            if(str1[i]!=str1[j]){
                return "";
            }
        }
        for(int i=g,j=0;i<str2.length();i++,j++){
            if(str2[i]!=str2[j]){
                return "";
            }
        }
        for(int i=0;i<g;i++){
            if(str1[i]!=str2[i]){
                return "";
            }
        }
        return str1.substr(0, g);
    }
};