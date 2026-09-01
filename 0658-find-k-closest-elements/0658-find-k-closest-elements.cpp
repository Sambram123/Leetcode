class Solution {
    int difference(int a,int x){
        return abs(a-x);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i:arr){
            int diff=difference(i,x);
            pq.push({diff,i});
        }

        while(k--){
            pair<int,int> p=pq.top();
            pq.pop();

            ans.push_back(p.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};