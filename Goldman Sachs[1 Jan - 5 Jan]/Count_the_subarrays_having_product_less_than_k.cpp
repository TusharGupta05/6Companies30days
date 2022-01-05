class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0;
        long long temp=1;
        for(int i=0,j=0;i<n && j<n; j++){
            temp*=a[j];
            if(temp>=k){
                while(temp>=k&&i<=j){
                    temp/=a[i];
                    i++;
                }
            }
            ans+=(j-i+1);
            
        }
        return ans;
    }
};
