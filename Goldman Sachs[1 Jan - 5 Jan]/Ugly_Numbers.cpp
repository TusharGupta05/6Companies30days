class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    vector<ull> v({1,2,3,4,5});
	    if(n<=5){
	        return v[n-1];
	    }
	    n-=5;
	    int i2=2,i3=1,i5=1;
	    while(n--){
	        while(v[i2]*2<=v.back()){
	            i2++;
	        }
	        while(v[i3]*3<=v.back()){
	            i3++;
	        }
	        while(v[i5]*5<=v.back()){
	            i5++;
	        }
	        ull v1=v[i2]*2;
	        ull v2=v[i3]*3;
	        ull v3=v[i5]*5;
	        v.push_back(min({v1,v2,v3}));
	    }
	    return v.back();
	}
};
