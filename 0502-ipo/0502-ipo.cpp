class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({capital[i],profits[i]});
        }
        sort(nums.begin(),nums.end());

        priority_queue<int> pq;
        int idx=0;
        while(k--){
            while(idx<n){
                if(w<nums[idx].first) break;
                else{
                    pq.push(nums[idx].second);
                }
                idx++;
            }
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};