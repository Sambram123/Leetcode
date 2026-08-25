class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int i=1;
        int n=k;
        while(true){
            if(st.find(k)==st.end()){
                return k;
            }
            else{
                i++;
                k=n*i;
            }
        }
        return -1;
    }
};