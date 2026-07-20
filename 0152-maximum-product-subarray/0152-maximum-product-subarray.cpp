class Solution {
public:
    int maxProduct(vector<int>& a) {
        int res=a[0];
        int min_product=a[0];
        int max_product=a[0];
        int n=a.size();

        for(int i=1;i<n;i++){
            int v1=a[i];
            int v2=max_product*a[i];
            int v3=min_product*a[i];
            max_product=max(v1,max(v2,v3));
            min_product=min(v1,min(v2,v3));

            res=max(res,max(max_product,min_product));
        }
        return res;
    }
};