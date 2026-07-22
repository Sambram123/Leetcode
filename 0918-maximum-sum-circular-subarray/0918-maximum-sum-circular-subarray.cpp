class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=nums[0];
        int ans1=nums[0];
        int ans2=nums[0];
        int minSum=nums[0];
        int totalSum=nums[0];
        int n=nums.size();
        

        for(int i=1;i<n;i++){
            maxSum=max(maxSum+nums[i],nums[i]);
            ans1=max(ans1,maxSum);

            minSum=min(minSum+nums[i],nums[i]);
            ans2=min(ans2,minSum);

            totalSum+=nums[i];
        }
        int circularSum=totalSum-ans2;

        if(circularSum==0) return ans1;
        return max(ans1,circularSum);
        
    }
};