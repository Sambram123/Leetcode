class Solution {
public:

    int sum(int num){
        int sum=0;
        while(num>0){
            int x=num%10;
            sum+=x;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num==0) return 0;
        int res=0;

        while(true){
           res = sum(num);
           num=res;
           if(res<10) break;
        }
        return res;
    }
};