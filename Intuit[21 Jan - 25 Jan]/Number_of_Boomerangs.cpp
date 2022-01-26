class Solution {
    int dist(const vector<int>& p1, const vector<int>& p2){
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return x*x + y*y;
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int,int> m;
            for(int j = 0; j < points.size(); j++){
                if(i == j){
                    continue;
                }
                int distance = dist(points[i], points[j]);
                m[distance]++;
                if(m[distance]>1){
                    ans += (m[distance]-1)*2;
                }
            }
        }
        return ans;
    }
};
