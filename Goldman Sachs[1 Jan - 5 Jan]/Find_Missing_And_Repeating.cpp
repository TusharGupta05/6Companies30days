class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int* ans = new int[2];
        for(int i=0;i<n;i++){
            int j = abs(arr[i])-1;
            if(arr[j]>0){
                arr[j]=-1*arr[j];
            } else {
                ans[0]=abs(arr[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1]=i+1;
            }
        }
        return ans;
    }
};
