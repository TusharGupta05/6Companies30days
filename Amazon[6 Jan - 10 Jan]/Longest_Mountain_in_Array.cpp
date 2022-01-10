class Solution {
public:
    int longestMountain(vector<int>& a) {
        int ans=0;
        int n=a.size();
        if(n<3){
            return ans;
        }
        int i=0;
        while(i<n&&a[i]>a[i+1]){
            i++;
        }
        while(i<n){
            int j=i;
            while(i+1<n&&a[i]<a[i+1]){
                i++;
            }
            if(i==j){
                i++;
                continue;
            }
            int sz=i-j+1;
            j=i;
            while(i+1<n&&a[i]>a[i+1]){
                i++;
                sz++;
            }
            if(i==j){
                i++;
                continue;
            }
            ans=max(ans, sz);
        }
        return ans;
    }
};
