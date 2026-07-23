class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int mW=0;
        while(i<j){
           int wt=j-i;
           int ht=min(height[i],height[j]);
           int area=wt*ht;
           
           mW=max(area,mW);
           if(height[i]<height[j]){
            i++;
           }else{
            j--;
           }

        }
        return mW;
    }
};