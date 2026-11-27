class Solution {
    // int fun(vector<int>& nums, int n, int i, int prev,vector<vector<int>>& dp){
    //     if(i==n){
    //         return dp[i][prev+1] = 0;
    //     }

    //     if(dp[i][prev+1] != -1){
    //         return dp[i][prev+1];
    //     }

    //     if(prev==-1 || nums[prev] < nums[i]){
    //         //take
    //         int yes = 1 + fun(nums,n,i+1,i,dp);
    //         //not take
    //         int no = fun(nums,n,i+1,prev,dp);
        
    //         return dp[i][prev+1] = max(yes,no);
    //     }
    //     return dp[i][prev+1] = fun(nums,n,i+1,prev,dp);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // int prev = -1;
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));

        // int ans = fun(nums,n,0,prev,dp);

        // return ans;

        int ans = INT_MIN;
        vector<int> dp(n);

        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }

        return ans;

    }
};