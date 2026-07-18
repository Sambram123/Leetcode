class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n>0){
            int x=n%10;
            sum+=(x*x);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        
        do{
            slow=sum(slow);
            fast=sum(sum(fast));
        }while(slow!=fast);
        
        return slow==1;
    }
};