class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int target = -nums[i];
            int start=i+1;
            int end=n-1;
            
            while(start<end){
                int sum = nums[start]+nums[end];
                if(sum==target){
                    ans.push_back({-target,nums[start],nums[end]});
                    start++;
                    end--;
                    while(start<n && nums[start]==nums[start-1])
                    start++;
                    while(end>0 && nums[end]==nums[end+1])
                    end--;
                }
                else if(sum<target)
                    start++;
                else
                    end--;
                
            }
        }
        return ans;
    }
};