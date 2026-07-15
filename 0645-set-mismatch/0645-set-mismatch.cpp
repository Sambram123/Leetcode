class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> freq(n+1,0);
        int duplicated,missing;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int j=1;j<=n;j++){
            if(freq[j]==0) missing=j;
            if(freq[j]>1) duplicated=j;
        }
        return {duplicated,missing};
    }
};