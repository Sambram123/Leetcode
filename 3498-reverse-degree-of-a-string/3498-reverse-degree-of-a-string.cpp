class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            int revDegree=(i+1)*abs((s[i]-'a')-26);
            ans+=revDegree;
        }

        return ans;
    }
};