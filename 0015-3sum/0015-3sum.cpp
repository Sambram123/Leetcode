class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int tar=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int i,j,k,sum;

        for(i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            j=i+1;k=n-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum>tar){
                    k--;
                }
                else if(sum<tar){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                }
            }
            
        }
        return ans;
    }
};