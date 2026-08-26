class Solution {
    long long getHours(vector<int> piles,int speed){
         long long hrs=0;
         for(int num:piles){
                hrs+=num/speed;
                if(num%speed!=0) hrs++;
            }
        return hrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int res=0;

        while(low<=high){
            int speed=low+(high-low)/2;
            long long hrs=getHours(piles,speed);

            if(hrs>h){
                low=speed+1;
            }else{
                res=speed;
                high=speed-1;
            }
        }
        return res;
    }
};