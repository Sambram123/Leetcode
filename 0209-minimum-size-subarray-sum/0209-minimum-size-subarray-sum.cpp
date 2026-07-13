class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int low=0;
        int res=INT_MAX;
        int n=nums.size();
        int sum=0;

        for(int high=0;high<n;high++){
            sum=sum+nums[high];

            while(sum>=k){
                int len=high-low+1;
                res=min(res,len);
                sum=sum-nums[low];
                low++;
            }
        }
        return res==INT_MAX?0:res;
    }
};