class Solution {
    void helper(vector<vector<int>>& ans, vector<int>& nums,vector<int> combs,int n,int i,int sum,int target){
        if(i==n){
            if(sum==target)
            ans.push_back(combs);
            return;
        }

        if(sum+nums[i]<=target){
            sum+=nums[i];
            combs.push_back(nums[i]);
            helper(ans,nums,combs,n,i,sum,target);
            sum-=nums[i];
            combs.pop_back();
           
        }
        
        helper(ans,nums,combs,n,i+1,sum,target);

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> combs;
        int sum=0;
        int i=0;

        helper(ans,nums,combs,n,i,sum,target);

        return ans;
    }
};