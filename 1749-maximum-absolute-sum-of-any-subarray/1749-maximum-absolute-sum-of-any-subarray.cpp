class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int res=abs(a[0]);
        int maxSum=a[0];
        int minSum=a[0];

        for(int i=1;i<a.size();i++){
            maxSum=max(a[i],maxSum+a[i]);
            minSum=min(a[i],minSum+a[i]);
            res=max({res,maxSum,abs(minSum)});
        }
        return res;
    }
};