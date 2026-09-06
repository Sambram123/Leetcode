class Solution {
    private:
    unordered_map<char,string> m;
        
    void helper(vector<string>& ans,string digits,int i,int n,string& str){
        if(i==n){
            ans.push_back(str);
            return;
        }
        string choice = m[digits[i]];
        for(char c:choice){
            str.push_back(c);
            helper(ans,digits,i+1,n,str);
            str.pop_back();
        }

        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";

        vector<string> ans;
        int n=digits.length();
        int i=0;
        string str="";

        helper(ans,digits,i,n,str);

        return ans;
    }
};