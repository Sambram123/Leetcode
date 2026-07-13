class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int n=nums.size();
        int zeros=0;
        int res=k;
       

        for(int high=0;high<n;high++){
            if(nums[high]==0) zeros++;
          
            while(zeros>k){
                if(nums[low]==0) zeros--;
                low++;
                
            }
            res=max(res,high-low+1);

        }
        return res;
    }
};