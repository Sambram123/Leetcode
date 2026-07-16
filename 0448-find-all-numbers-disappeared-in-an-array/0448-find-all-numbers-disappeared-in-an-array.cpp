class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp(n);
        vector<int> ans;

        for(int num:nums){
            mp[num]++;
        }
        for(int j=1;j<=n;j++){
            if(mp.find(j)==mp.end()) ans.push_back(j);
        }
        return ans;
    }
};