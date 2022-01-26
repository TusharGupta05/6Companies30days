class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<int> order, cnt(n, 0);
        vector<vector<int>> edges(n);
        for(int i=0;i<preq.size();i++){
            edges[preq[i][1]].push_back(preq[i][0]);
            cnt[preq[i][0]]++;
        }
        queue<int> trav;
        for(int i=0;i<n;i++){
            if(cnt[i]==0){
                trav.push(i);
            }
        }
        while(!trav.empty()){
            order.push_back(trav.front());
            for(int course:edges[trav.front()]){
                cnt[course]--;
                if(cnt[course]==0){
                    trav.push(course);
                }
            }
            trav.pop();
        }
        if(order.size()==n){
            return order;
        }
        return {};
    }
};
