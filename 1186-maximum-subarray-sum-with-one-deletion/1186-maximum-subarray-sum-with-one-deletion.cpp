class Solution {
public:
    int maximumSum(vector<int>& a) {
        int res=a[0];
        int noDelete=a[0];
        int oneDelete=INT_MIN;

        for(int i=1;i<a.size();i++){
            int prevNoDelete=noDelete;
            int prevOneDelete=oneDelete;

            noDelete=max(noDelete+a[i],a[i]);
            int v2;
            if(prevOneDelete==INT_MIN)
                v2=a[i];
            else
                v2=prevOneDelete+a[i];
            oneDelete=max(prevNoDelete,v2);

            res=max(res,max(oneDelete,noDelete));
        }
        return res;
    }
};