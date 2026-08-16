class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> have,need;

        for(char c:magazine){
            have[c]++;
        }
        for(char c:ransomNote){
            need[c]++;
        }
    
       for(auto i:need){
        if(i.second>have[i.first]) return false;
       }

        return true;
    }
};