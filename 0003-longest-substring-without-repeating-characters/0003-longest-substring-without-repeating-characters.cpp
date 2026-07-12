class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0,high=0;
        int res=0;
        unordered_map<char,int> mp;
        int n=s.size();

        for(high=0;high<n;high++){
            mp[s[high]]++;
            int k=high-low+1;

            while(mp.size()<k){
                mp[s[low]]--;
                if(mp[s[low]]==0)
                    mp.erase(s[low]);
                low++;
                k=high-low+1;
            }
            if(mp.size()==k){
                int len=high-low+1;
                res=max(res,len);
            }
        }
        return res;
    }
};