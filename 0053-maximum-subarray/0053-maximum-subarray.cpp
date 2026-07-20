class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int best_sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int v1=best_sum+nums[i];
            int v2=nums[i];
            best_sum=max(v1,v2);
            res=max(res,best_sum);
        }
        return res;
    }
};