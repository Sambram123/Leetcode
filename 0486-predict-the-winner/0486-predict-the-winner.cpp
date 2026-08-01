class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        for (int left = n - 1; left >= 0; left--) {
            dp[left] = nums[left];

            for (int right = left + 1; right < n; right++) {
                dp[right] = max(
                    nums[left] - dp[right],
                    nums[right] - dp[right - 1]
                );
            }
        }

        return dp[n - 1] >= 0;
    }
};
 
