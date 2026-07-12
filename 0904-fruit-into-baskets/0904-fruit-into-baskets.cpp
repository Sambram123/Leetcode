class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0,high=0;
        int res=-1;
        unordered_map<int,int> mp;
        int n=fruits.size();
        for(high=0;high<n;high++){
            mp[fruits[high]]++;
            while(mp.size()>2){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0)
                    mp.erase(fruits[low]);
                low++;
            }
            if(mp.size()<=2){
                int len=high-low+1;
                res=max(res,len);
            }
        }
        return res;
    }
};