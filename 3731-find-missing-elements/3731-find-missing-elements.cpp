class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        for(int i=mini;i<=maxi;i++){
            if(s.find(i)==s.end()) ans.push_back(i);
        }
        return ans;
    }
};