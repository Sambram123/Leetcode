class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

       for(auto i:m){
            int ele=i.first;
            int freq=i.second;
            pair<int,int> curr={freq,ele};

            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            
            if(curr.first<pq.top().first) continue;
            else{
                pq.pop();
                pq.push(curr);
            }
       }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};