/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int low = 1, high = len-2;
        int peakIdx;
        while(low<=high){
            int mid = (low+high)/2;
            int before = mountainArr.get(mid-1);
            int after = mountainArr.get(mid+1);
            int cur = mountainArr.get(mid);
            if(before<cur&&cur<after){
                low = mid+2;
                peakIdx = mid+1;
            } else if(before<cur&&cur>after){
                peakIdx = mid;
                break;
            } else {
                peakIdx = mid-1;
                high = mid-2;
            }
        }
        low = 0, high = peakIdx;
        while(low<=high){
            int mid = (low+high)/2;
            int val = mountainArr.get(mid);
            if(val<target){
                low=mid+1;
            } else if(val==target){
                return mid;
            } else {
                high = mid-1;
            }
        }
        low = peakIdx + 1, high = len-1;
        while(low<=high){
            int mid = (low+high)/2;
            int val = mountainArr.get(mid);
            if(val<target){
                high = mid-1;
            } else if(val==target){
                return mid;
            } else {
                low = mid+1;
            }
        }
        return -1;
    }
};
