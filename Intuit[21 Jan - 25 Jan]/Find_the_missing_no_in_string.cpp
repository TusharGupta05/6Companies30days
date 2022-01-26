// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str){
    int ans = -1;
    int n = str.length();
    for(int i=0;i<min(n, 6);i++){
        int st = 0;
        for(int k=0;k<=i;k++){
            st*=10;
            st+=str[k]-'0';
        }
        int j = i+1;
        int missing = 0;
        int tempans = -1;
        while(j<n&&missing<2){
            int nextLen = to_string(st+1).length();
            int nextNextLen = to_string(st+2).length();
            int temp = 0;
            int mx = min(j+nextLen, n);
            for(;j<mx;j++){
                temp*=10;
                temp+=str[j]-'0';
            }
            if(temp == st+1){
                st = temp;
                continue;
            }
            if(temp == st+2){
                tempans = st+1;
                missing++;
                st = temp;
                continue;
            }
            if(nextNextLen > nextLen && j < n){
                temp*=10;
                temp+=str[j]-'0';
                if(temp!=st+2){
                    missing = 2;
                    break;
                }
                j++;
                tempans = temp-1;
                st = temp;
                missing++;
                continue;
            }
            missing = 2;
            break;
        }
        if(missing==1){
            ans = tempans;
            break;
        }
    }
    return ans;
}
