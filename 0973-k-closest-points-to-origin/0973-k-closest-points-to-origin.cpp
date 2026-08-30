class Solution {
    double distance(int x,int y){
        return sqrt((x*x)+(y*y));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        int n=points.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            double dist=distance(points[i][0],points[i][1]);
            if(pq.size()<k){
                pq.push({dist,i});
                continue;
            }
            pq.push({dist,i});
            pq.pop();  
        }

        while(!pq.empty()){
            int idx=pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }

        return ans;
    }
};