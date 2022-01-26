class Solution {
    bool check(vector<int>& piles, int h, int k){
        int cnt=0;
        for(int i:piles){
            cnt+=(i+k-1)/k;
        }
        return cnt<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int low=1, high = *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(piles, h, mid)){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};
