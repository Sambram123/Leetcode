class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int res=abs(a[0]);
        int maxSum=a[0];
        int minSum=a[0];
        int n=a.size();
        for(int i=1;i<n;i++){
            maxSum=max(a[i],maxSum+a[i]);
            minSum=min(a[i],minSum+a[i]);
            res=max(res,max(maxSum,abs(minSum)));
        }
        return res;
    }
};