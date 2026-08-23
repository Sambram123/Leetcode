class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int idx=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=nums[mid+1]){
                idx=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return idx;
    }
};