class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int idx=-1;
        vector<int> maxes(n,0);
        vector<int> minis(n,0);

        maxes[0]=nums[0];
        minis[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            maxes[i]=max(nums[i],maxes[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            minis[i]=min(nums[i],minis[i+1]);
        }

        for(int i=0;i<n;i++){
            int maxi=maxes[i];
            int mini=minis[i];

            int score=maxi-mini;
            if(score<=k){
                idx=i;
                break;
            }
        }

        return idx;
    }
};