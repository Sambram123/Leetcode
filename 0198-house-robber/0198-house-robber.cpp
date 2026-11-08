class Solution {
    vector<int> dp;

    int fun(vector<int>& nums, int i, int n) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        // Rob current house
        int rob = nums[i] + fun(nums, i + 2, n);

        // Don't rob current house
        int notRob = fun(nums, i + 1, n);

        return dp[i] = max(rob, notRob);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n, -1);

        return fun(nums, 0, n);
    }
};