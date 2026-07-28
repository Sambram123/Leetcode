class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string res="";
        
        sort(s.begin(),s.begin()+n/2);
        sort(s.end()-n/2,s.end());
        reverse(s.end()-n/2,s.end());

        return s;
    }
};