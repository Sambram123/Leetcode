class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n=k;
        while(true){
            if(st.find(n)==st.end()){
                return n;
            }
            else{
                n+=k;
            }
        }
        return -1;
    }
};