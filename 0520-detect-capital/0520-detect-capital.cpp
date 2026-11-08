class Solution {
public:

    
    bool detectCapitalUse(string word) {
        int count=0;
        int n=word.size();

        if(n==1)return true;

        for(int i=0;i<n;i++)
            if(isupper(word[i]))count++;

            if(count==1 && isupper(word[0]))return true;

            if(count==0 || count==n) return true;
            else
                return false;
        
        
    }
};