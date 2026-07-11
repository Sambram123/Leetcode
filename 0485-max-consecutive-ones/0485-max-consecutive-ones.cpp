class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, res = 0;

        for (int x : nums) {
            if (x == 1) {
                cnt++;
                res = max(res, cnt);
            } else {
                cnt = 0;
            }
        }

        return res;
    }
};