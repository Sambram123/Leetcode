class Solution {
    int smaller(vector<vector<int>> matrix,int n,int m,int mid){
        int lesser=0;
        int row=n-1;
        int col=0;

        while(row>=0 && col<n){
            if(matrix[row][col]>mid) row--;
            else{
                lesser+=row+1;
                col++;
            }
        }
        return lesser;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        
        int res=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int lesser=smaller(matrix,n,m,mid);
            if(lesser<k)
              low=mid+1;
            else{
                res=mid;
                high=mid-1;
            }

        }
        return res;
    }
};