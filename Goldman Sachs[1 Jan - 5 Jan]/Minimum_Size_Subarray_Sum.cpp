class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int runSum=0;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0, j=0; i<n && j<n; j++){
            runSum+=nums[j];
            if(runSum>=target){
                while(i<j&&runSum-nums[i]>=target){
                    runSum-=nums[i];
                    i++;
                }
                ans=min(ans, j-i+1);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
