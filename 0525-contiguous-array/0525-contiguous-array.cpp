class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0;
        int ones=0;
        int zeros=0;
        unordered_map<int,int> m;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==0) zeros++;
            else ones++;
            int diff=zeros-ones;

            if(diff==0){
                res=max(res,i+1);
                continue;
            }

            if(m.find(diff)==m.end()){
                 m[diff]=i;
                
            }
            else{
               int idx=m[diff];
                int len=i-idx;
                res=max(res,len);
            }
        }
        return res;
    }
};