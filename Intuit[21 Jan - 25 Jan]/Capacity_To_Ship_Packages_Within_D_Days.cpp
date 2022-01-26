class Solution {
    bool check(vector<int>& weights, int days, int capacity){
        int cnt = 0, run_sum = 0;
        for(int i : weights){
            if(run_sum+i <= capacity){
                run_sum += i;
            } else {
                cnt++;
                run_sum = i;
            }
        }
        cnt++;
        return cnt <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
        int ans=0;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(weights, days, mid)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};
