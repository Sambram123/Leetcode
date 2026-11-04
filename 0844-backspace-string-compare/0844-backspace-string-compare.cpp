class Solution {
public:
    string buildString(string &str){
        
        stack<char> result;
        for(char ch: str){
            if(ch=='#'){
                if(!result.empty()) result.pop();
            }else{
                result.push(ch);
            }
        }
        
        string restring="";
        while(!result.empty()){
            restring = result.top()+restring;
            result.pop();
        }
        return restring;

    }
    bool backspaceCompare(string s, string t) {
        
        return buildString(s)== buildString(t);
    }
};