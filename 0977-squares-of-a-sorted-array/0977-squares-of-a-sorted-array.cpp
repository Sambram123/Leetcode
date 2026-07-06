class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        
        int m = pos.size();
        int n = neg.size();
        

        if(m==0){
            for(int i=0;i<n;i++){
                neg[i]=neg[i]*neg[i];  
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        if(n==0){
            for(int i=0;i<m;i++){
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }

        int i=0;
        int j=0;
        int idx=0;
        vector<int> res(m+n);
         for(int i=0;i<n;i++){
                neg[i]=neg[i]*neg[i];
            }
        reverse(neg.begin(),neg.end());
        for(int i=0;i<m;i++){
                pos[i]=pos[i]*pos[i];
            }

        while(i<m && j<n){
            if(pos[i]<=neg[j]){
                res[idx]=pos[i];
                idx++;
                i++;
            }
            else{
                res[idx]=neg[j];
                idx++;
                j++;
            }
        }
        while(i<m){
             res[idx]=pos[i];
                idx++;
                i++;
        }
        while(j<n){
            res[idx]=neg[j];
                idx++;
                j++;
        }
        return res;
    }
};