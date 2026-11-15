class Solution {
    
    int fun(int n,vector<int>& dp){
        if(n==1) return dp[n] = 1;
        if(n==2) return dp[n] = 2;

        if(dp[n]!=-1)
            return dp[n];

        int c1 = fun(n-1,dp);
        int c2 = fun(n-2,dp);

        return dp[n] = c1+c2;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};