class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool isNonZero=false;
        int total=0;
        int n=nums.size();

        for(int num:nums){
            if(num!=0) isNonZero=true;
            total^=num;
        }

        if(total!=0) return n;
        if(isNonZero) return n-1;

        return 0;

    }
};