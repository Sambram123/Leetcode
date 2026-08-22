class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int n=nums.size();
        int low=0;
        int high=n-1;
        int start=-1,end=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target) low=mid+1;
            else if(nums[mid]>target) high=mid-1;
            else {
                start=mid;
                high=mid-1;
            }
        }
        ans[0]=start;

        low=0;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target) low=mid+1;
            else if(nums[mid]>target) high=mid-1;
            else{
                end=mid;
                low=mid+1;
            }
        }
        ans[1] = end;

        return ans;
    }
};