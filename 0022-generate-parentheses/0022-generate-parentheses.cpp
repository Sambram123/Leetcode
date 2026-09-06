class Solution {
    void generate(int n,int open,int close,string tmp,vector<string>& ans){
        if(open==n && close==n){
            ans.push_back(tmp);
            return;
        }

        if(open<n){
            tmp.push_back('(');
            generate(n,open+1,close,tmp,ans);
            tmp.pop_back();
        }

        if(close<open){
            tmp.push_back(')');
            generate(n,open,close+1,tmp,ans);
            tmp.pop_back();
        }


        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string str="";
        vector<string> ans;
        generate(n,0,0,str,ans);

        return ans;
    }
};