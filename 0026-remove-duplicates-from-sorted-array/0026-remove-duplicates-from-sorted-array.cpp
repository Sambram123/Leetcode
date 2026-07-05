class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=i+1;
        int n=nums.size();
        int res=1;

        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                res++;
                nums[i+1]=nums[j];
                i++;
            }
        }
        return res;
    }
};