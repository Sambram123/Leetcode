class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> have,need;
        int res=INT_MAX;

        for(char c:text){
            have[c]++;
        }
        for(char c:string("balloon")){
            need[c]++;
        }

        for(auto i:need){
            char c=i.first;
            int fneed=i.second;
            int fhave=have[c];
            int times=fhave/fneed;
            res=min(res,times);
        }
        return res;
    }
};