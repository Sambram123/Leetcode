class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int right=sum-nums[0]-left;
        if(left==right) return 0;

        for(int i=1;i<n;i++){
            left+=nums[i-1];
            right=sum-nums[i]-left;
            if(left==right) return i;
        }
        return -1;
    }
};