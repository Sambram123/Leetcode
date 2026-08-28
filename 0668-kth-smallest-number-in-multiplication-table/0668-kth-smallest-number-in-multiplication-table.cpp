class Solution {
    int smaller(int m,int n,int guess){
        int count=0;

        for(int i=1;i<=m;i++){
            count+=min(n,guess/i);
        }
        return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int res;
    
        int low=1;
        int high=m*n;

        while(low<=high){
            int guess=low+(high-low)/2;
            int ans=smaller(m,n,guess);

            if(ans<k){
                low=guess+1;
            }else{
                res=guess;
                high=guess-1;
            }
        }
    return res;
    }
};