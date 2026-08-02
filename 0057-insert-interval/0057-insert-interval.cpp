class Solution {
    vector<vector<int>> mergeInterval(vector<vector<int>>& ans){
        int start1=ans[0][0];
        int end1=ans[0][1];
        int n=ans.size();

        vector<vector<int>> res;

        for(int i=1;i<n;i++){
            int start2=ans[i][0];
            int end2=ans[i][1];

            if(end1>=start2){
                end1=max(end1,end2);
                continue;
            }
            res.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }
        res.push_back({start1,end1});
        return res;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<vector<int>> res;
        int n=intervals.size();
        bool insert=false;

        for(int i=0;i<n;i++){
            if(newInterval[0]<=intervals[i][0] && insert==false){
                ans.push_back(newInterval);
                insert=true;
            }
            ans.push_back(intervals[i]);
        }
        if(insert==false) ans.push_back(newInterval);

        res = mergeInterval(ans);
        return res;
    }
};