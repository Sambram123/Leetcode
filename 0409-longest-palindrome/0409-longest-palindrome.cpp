class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int res=0;
        bool hasOdd=false;

        for(char c:s){
            mp[c]++;
        }

        for(auto i:mp){
            char c=i.first;
            int count=i.second;

            if(count%2==0) res+=count;
            else{
                res+=(count-1);
                hasOdd=true;  
            }
        }
        if(hasOdd) res++;

        return res;
    }
};