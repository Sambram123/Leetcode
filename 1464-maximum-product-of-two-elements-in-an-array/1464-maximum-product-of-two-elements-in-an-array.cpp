class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1,max2=INT_MIN;

        for(int n:nums){
            if(n>=max1){
                max2=max1;
                max1=n;
            }
            else if(n>=max2 && n<max1){
                max2=n;
            }
        }
        return (max1-1)*(max2-1);
    }
};