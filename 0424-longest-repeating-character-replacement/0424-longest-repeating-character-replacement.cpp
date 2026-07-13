class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0,high=0,n=s.size();
        vector<int> arr(256,0);
        int res=INT_MIN;
        int maxcnt=0;

        for(high=0;high<n;high++){
            arr[s[high]-'A']++;
            maxcnt=max(maxcnt,arr[s[high]-'A']);
            int len=high-low+1;
            int diff=len-maxcnt;

            while(diff>k){
                arr[s[low]-'A']--;
                low++;
                len=high-low+1;
                diff=len-maxcnt;
            }
            res=max(res,len);
        }
        return res;
    }
};